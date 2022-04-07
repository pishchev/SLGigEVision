#pragma once

#include "SLGigEVision_i.h"
#include "GigeManager.hpp"

// CSLGigEVisionMgr
class ATL_NO_VTABLE CSLGigEVisionMgr :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSLGigEVisionMgr, &CLSID_SLGigEVisionMgr>,
	public ISLGigEVisionMgr
{
public:
	CSLGigEVisionMgr()
	{
		m_pUnkMarshaler = nullptr;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_SLGIGEVISIONMGR)
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CSLGigEVisionMgr)
		COM_INTERFACE_ENTRY(ISLGigEVisionMgr)
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
	// ISLGigEVisionMgr
	STDMETHOD(GetCamCount)(LONG* oCamNumber);
	STDMETHOD(GetCamInfo)(LONG iCamIndex, LONG* oWidth, LONG* oHeight, double* oFPS, BSTR* oName, BSTR* oID);
	STDMETHOD(GetCamObject)(LONG iCamIndex, ISLGigEVisionCam* *oISLGigEVisionCam);
};
//
OBJECT_ENTRY_AUTO(__uuidof(SLGigEVisionMgr), CSLGigEVisionMgr)
