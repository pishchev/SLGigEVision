#include <iostream>
#include <iomanip>
#include <objbase.h>
#include <comdef.h>
#include <string>
#include <chrono>
#include <atlbase.h>

#include "../SLGigEVision/SLGigEVision_i.h"
#include "../SLGigEVision/SLGigEVision_i.c"

std::string BSTRToString(const BSTR& iBSTR) {
  char str[MAX_PATH * 2];
  WideCharToMultiByte(CP_ACP, 0, iBSTR, -1, str, _countof(str), NULL, NULL);
  return std::string(str);
}

void Capture(ISLGigEVisionCam* camera, size_t payloadSize, unsigned char* image)
{
  size_t i = 0;
  size_t min = 0;
  size_t max = 0;
  double timestamp = 0;
  double lastTimestamp = 0;
  auto chrono = std::chrono::steady_clock::now();

  while (i < 100) {

    camera->GetFifoInfo((LONG*)&min, (LONG*)&max);

    if (i < min + 2) {
      std::cout << "SLOW " << i << "->" << i + 2 << std::endl;
      i = min + 2;
    }

    if (camera->GetImage((LONG)i, eSLGEVImagePixelFormat::eIP_RGB24_FAST, image, (LONG)payloadSize, &timestamp) == S_OK) {
      const auto lastChrono = chrono;
      chrono = std::chrono::steady_clock::now();
      std::cout << "Image[" << i
        << "] " << min << "-" << max
        << "; Timestamp: " << timestamp
        << "; DeltaTimestamp: " << timestamp - lastTimestamp
        << "; DeltaChrono: " << std::chrono::duration_cast<std::chrono::microseconds>(chrono - lastChrono).count()
        << std::endl;
      i++;
      lastTimestamp = timestamp;
    }
    else Sleep(1);
  }
}

int main()
{
  std::cout << "Start client" << std::endl;

  HRESULT coIn = CoInitializeEx(nullptr, COINIT::COINIT_MULTITHREADED);
  if (!SUCCEEDED(coIn)) {
    std::cout << "CoInitializeEx error" << std::endl;
    return 1;
  }

  ISLGigEVisionMgr* mgr;

  HRESULT hr = CoCreateInstance(CLSID_SLGigEVisionMgr, nullptr, CLSCTX_INPROC_SERVER, IID_ISLGigEVisionMgr, (LPVOID*)&mgr);
  if (!SUCCEEDED(hr)) {
    std::cout << "Instance fail" << std::endl;
    return 1;
  }

  LONG configCount = 0;
  mgr->GetCamCount(&configCount);

  for (LONG i = 0; i < configCount; ++i) {
    BSTR name, id;
    LONG width = 0;
    LONG height = 0;
    double fps = 0;

    mgr->GetCamInfo(i, &width, &height, &fps, &name, &id);
    std::cout << i << ") Name: " << BSTRToString(name) << " " << width << "x" << height << "p" << fps <<std::endl;
  }

  LONG camIndex = 0;
  std::cout << "Camera: ";
  std::cin >> camIndex;

  ISLGigEVisionCam* camera;
  mgr->GetCamObject(camIndex, &camera);

  size_t width = 0;
  size_t height = 0;
  camera->GetImageInfo((LONG*)&width, (LONG*)&height);
  size_t payloadSize = width * height * 3;

  std::cout << "PayloadSize: " << payloadSize << "; Width: " << width << "; Height: " << height << std::endl;
  unsigned char* image = new unsigned char[payloadSize];

  camera->Start();
  Capture(camera, payloadSize, image);
  camera->Stop();
  camera->Start();
  Capture(camera, payloadSize, image);
  
  return 0;
}