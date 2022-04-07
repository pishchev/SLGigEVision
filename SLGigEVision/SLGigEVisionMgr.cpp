#include "stdafx.h"
#include "SLGigEVisionMgr.h"

// CSLGigEVisionMgr
STDMETHODIMP CSLGigEVisionMgr::GetCamCount(LONG* oCamNumber)
{
	if (NULL == oCamNumber)  return E_POINTER;
	*oCamNumber = 1;
	return S_OK;
}

STDMETHODIMP CSLGigEVisionMgr::GetCamInfo(LONG iCamIndex, LONG* oWidth, LONG* oHeight, double* oFPS, BSTR* oName, BSTR* oID)
{
	if (iCamIndex < 0 || iCamIndex >= 1)  return E_INVALIDARG;
	if (NULL != oWidth)  *oWidth = 640;
	if (NULL != oHeight)  *oHeight = 640;
	if (NULL != oFPS)  *oFPS = 200.0;
	if (NULL != oName)  *oName = CComBSTR(L"TEST").Detach();
	if (NULL != oID)  *oID = CComBSTR(L"TEST").Detach();
	return S_OK;
}

STDMETHODIMP CSLGigEVisionMgr::GetCamObject(LONG iCamIndex, ISLGigEVisionCam* *oISLGigEVisionCam)
{
	if (iCamIndex < 0 || iCamIndex >= 1)  return E_INVALIDARG;
	if (NULL == oISLGigEVisionCam)  return E_POINTER;

	CComPtr<IUnknown> pICam;
	HRESULT hres = pICam.CoCreateInstance(CLSID_SLGigEVisionCam);
	if (S_OK != NULL)  return hres;
	CComQIPtr<ISLGigEVisionCamInit> pInit(pICam);
	if (NULL == pInit)  return E_UNEXPECTED;
	hres = pInit->Init(CComBSTR(L"C:\\SLGigEVision\\Test.txt"));
	if (S_OK != NULL)  return hres;
	return pICam->QueryInterface(IID_ISLGigEVisionCam, (void**)oISLGigEVisionCam);
}
