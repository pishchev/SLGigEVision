#include "stdafx.h"
#include "SLGigEVisionMgr.h"

// CSLGigEVisionMgr
STDMETHODIMP CSLGigEVisionMgr::GetCamCount(LONG* oCamNumber)
{
	if (NULL == oCamNumber)  return E_POINTER;

	WIN32_FIND_DATAW wfd;
	HANDLE const hFind = FindFirstFileW(L"D:\\GigeVisionConfigurations\\*.gvc", &wfd);

	LONG configsCount = 0;
	if (INVALID_HANDLE_VALUE != hFind) {
		do {
			configsCount++;
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}
	*oCamNumber = configsCount;

	return S_OK;
}

STDMETHODIMP CSLGigEVisionMgr::GetCamInfo(LONG iCamIndex, LONG* oWidth, LONG* oHeight, double* oFPS, BSTR* oName, BSTR* oID)
{
	LONG maxCount = 0;
	GetCamCount(&maxCount);
	if (iCamIndex < 0 || iCamIndex >= maxCount)  return E_INVALIDARG;

	Configurator config;
	const auto camFile = GetCamFile(iCamIndex);
	config.ReadConfig(camFile);

	if (NULL != oWidth)  *oWidth = std::atoi(config._parameters["Width"].value.c_str());
	if (NULL != oHeight)  *oHeight = std::atoi(config._parameters["Height"].value.c_str());
	if (NULL != oFPS)  *oFPS = config._fps;
	if (NULL != oName)  *oName = CComBSTR(config._name.c_str()).Detach();
	if (NULL != oID)  *oID = CComBSTR(config._name.c_str()).Detach();
	return S_OK;
}

STDMETHODIMP CSLGigEVisionMgr::GetCamObject(LONG iCamIndex, ISLGigEVisionCam* *oISLGigEVisionCam)
{
	LONG maxCount = 0;
	GetCamCount(&maxCount);
	if (iCamIndex < 0 || iCamIndex >= maxCount)  return E_INVALIDARG;
	if (NULL == oISLGigEVisionCam)  return E_POINTER;

	CComPtr<IUnknown> pICam;
	HRESULT hres = pICam.CoCreateInstance(CLSID_SLGigEVisionCam);
	if (S_OK != NULL)  return hres;
	CComQIPtr<ISLGigEVisionCamInit> pInit(pICam);
	if (NULL == pInit)  return E_UNEXPECTED;
	const auto camFile = GetCamFile(iCamIndex);
	hres = pInit->Init(CComBSTR(camFile.c_str()).Detach());
	if (S_OK != NULL)  return hres;
	return pICam->QueryInterface(IID_ISLGigEVisionCam, (void**)oISLGigEVisionCam);
}

std::string CSLGigEVisionMgr::GetCamFile(LONG iCamIndex)
{
	WIN32_FIND_DATAW wfd;
	HANDLE const hFind = FindFirstFileW(L"D:\\GigeVisionConfigurations\\*.gvc", &wfd);
	for (LONG i = 0; i < iCamIndex; ++i)
		FindNextFileW(hFind, &wfd);

	std::wstring wstrConfig(&wfd.cFileName[0]);
	std::string strConfig(wstrConfig.begin(), wstrConfig.end());
	return strConfig;
}
