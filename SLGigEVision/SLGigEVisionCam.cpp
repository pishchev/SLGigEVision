#include "stdafx.h"
#include "SLGigEVisionCam.h"

STDMETHODIMP CSLGigEVisionCam::Init(BSTR iFile)
{
	char str[MAX_PATH * 2];
	WideCharToMultiByte(CP_ACP, 0, iFile, -1, str, _countof(str), NULL, NULL);
	std::string szFileName(str);
	_gigeManager.UseConfigurator(szFileName);
	return S_OK;
}

STDMETHODIMP CSLGigEVisionCam::Stop()
{
	_gigeManager.StopAcquisition();
	return S_OK;
}

STDMETHODIMP CSLGigEVisionCam::Start()
{
	_gigeManager.AcquirerPreparing();
	_gigeManager.StartAcquisition();
	return S_OK;
}

STDMETHODIMP CSLGigEVisionCam::GetImage(LONG iImageIndex, eSLGEVImagePixelFormat iFormat, BYTE* oImage, LONG iImageSize, double* oImageTimeInSec)
{
	// check params

	switch (iFormat) {
	case eSLGEVImagePixelFormat::eIP_RAW:
		_gigeManager.SetConverter(ConverterType::Raw);
		break;
	case eSLGEVImagePixelFormat::eIP_RGB24_FAST:
		_gigeManager.SetConverter(ConverterType::Bayer_RGB24_NoInt);
		break;
	case eSLGEVImagePixelFormat::eIP_RGB24_FINE:
		_gigeManager.SetConverter(ConverterType::Bayer_RGB24_Int);
		break;
	case eSLGEVImagePixelFormat::eIP_UYVY_FAST:
		_gigeManager.SetConverter(ConverterType::Bayer_UYVY_NoInt);
		break;
	case eSLGEVImagePixelFormat::eIP_UYVY_FINE:
		_gigeManager.SetConverter(ConverterType::Bayer_UYVY_Int);
		break;
	}

	const auto res = _gigeManager.GetImage((size_t)iImageIndex, oImage) ? S_OK : S_FALSE;
	if (res == S_OK) {
		size_t tmp = 0;
		_gigeManager.GetTimestamp((size_t)iImageIndex, tmp);
		*oImageTimeInSec = (double)tmp / 100000.0;
	}

	return res;
}

STDMETHODIMP CSLGigEVisionCam::GetImageInfo(LONG* oWidth, LONG* oHeight)
{
	int64_t width = 0;
	int64_t height = 0;

	_gigeManager.GetIntNode("Width", width);
	_gigeManager.GetIntNode("Height", height);

	if (NULL != oWidth) *oWidth = (LONG)width;
	if (NULL != oHeight) *oHeight = (LONG)height;
	return S_OK;
}

STDMETHODIMP CSLGigEVisionCam::GetFifoInfo(LONG* oMinIndex, LONG* oMaxIndex)
{
	size_t min, max;
	_gigeManager.GetBufferInfo(min, max);
	if (NULL != oMinIndex) *oMinIndex = (LONG)min;
	if (NULL != oMaxIndex) *oMaxIndex = (LONG)max;
	return S_OK;
}
