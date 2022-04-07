#pragma once
#include "SLGigEVision_i.h"
#include "GigeManager.hpp"

// CSLGigEVisionCam
class ATL_NO_VTABLE CSLGigEVisionCam :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSLGigEVisionCam, &CLSID_SLGigEVisionCam>,
	public ISLGigEVisionCamInit,
	public ISLGigEVisionCam
{
public:
	CSLGigEVisionCam()
	{
		m_pUnkMarshaler = nullptr;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_SLGIGEVISIONCAM)
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CSLGigEVisionCam)
		COM_INTERFACE_ENTRY(ISLGigEVisionCam)
		COM_INTERFACE_ENTRY(ISLGigEVisionCamInit)
		COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	END_COM_MAP()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

private:
	CComPtr<IUnknown> m_pUnkMarshaler;
	//
	GigeManager _gigeManager;

public:
	// ISLGigEVisionCamInit
	STDMETHOD(Init)(BSTR iFile);
	// ISLGigEVisionCam
	STDMETHOD(Stop)();
	STDMETHOD(Start)();
	STDMETHOD(GetImage)(LONG iImageIndex, eSLGEVImagePixelFormat iFormat, BYTE* oImage, LONG iImageSize, double* oImageTimeInSec);
	STDMETHOD(GetImageInfo)(LONG* oWidth, LONG* oHeight);
	STDMETHOD(GetFifoInfo)(LONG* oMinIndex, LONG* oMaxIndex);
};
//
OBJECT_ENTRY_AUTO(__uuidof(SLGigEVisionCam), CSLGigEVisionCam)
