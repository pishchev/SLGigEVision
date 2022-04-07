// dllmain.h : Declaration of module class.

class CSLGigEVisionModule : public ATL::CAtlDllModuleT< CSLGigEVisionModule >
{
public :
	DECLARE_LIBID(LIBID_SLGigEVisionLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SLGIGEVISIONLIB, "{07277cb7-d484-433a-a226-bc5cf676ff0a}")
};

extern class CSLGigEVisionModule _AtlModule;
