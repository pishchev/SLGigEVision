

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 10:14:07 2038
 */
/* Compiler settings for SLGigEVision.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SLGigEVision_i_h__
#define __SLGigEVision_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISLGigEVisionCam_FWD_DEFINED__
#define __ISLGigEVisionCam_FWD_DEFINED__
typedef interface ISLGigEVisionCam ISLGigEVisionCam;

#endif 	/* __ISLGigEVisionCam_FWD_DEFINED__ */


#ifndef __ISLGigEVisionCamInit_FWD_DEFINED__
#define __ISLGigEVisionCamInit_FWD_DEFINED__
typedef interface ISLGigEVisionCamInit ISLGigEVisionCamInit;

#endif 	/* __ISLGigEVisionCamInit_FWD_DEFINED__ */


#ifndef __ISLGigEVisionMgr_FWD_DEFINED__
#define __ISLGigEVisionMgr_FWD_DEFINED__
typedef interface ISLGigEVisionMgr ISLGigEVisionMgr;

#endif 	/* __ISLGigEVisionMgr_FWD_DEFINED__ */


#ifndef __SLGigEVisionMgr_FWD_DEFINED__
#define __SLGigEVisionMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class SLGigEVisionMgr SLGigEVisionMgr;
#else
typedef struct SLGigEVisionMgr SLGigEVisionMgr;
#endif /* __cplusplus */

#endif 	/* __SLGigEVisionMgr_FWD_DEFINED__ */


#ifndef __SLGigEVisionCam_FWD_DEFINED__
#define __SLGigEVisionCam_FWD_DEFINED__

#ifdef __cplusplus
typedef class SLGigEVisionCam SLGigEVisionCam;
#else
typedef struct SLGigEVisionCam SLGigEVisionCam;
#endif /* __cplusplus */

#endif 	/* __SLGigEVisionCam_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_SLGigEVision_0000_0000 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum eSLGEVImagePixelFormat
    {
        eIP_RAW	= 0,
        eIP_RGB24_FAST	= ( eIP_RAW + 1 ) ,
        eIP_RGB24_FINE	= ( eIP_RGB24_FAST + 1 ) ,
        eIP_UYVY_FAST	= ( eIP_RGB24_FINE + 1 ) ,
        eIP_UYVY_FINE	= ( eIP_UYVY_FAST + 1 ) 
    } 	eSLGEVImagePixelFormat;



extern RPC_IF_HANDLE __MIDL_itf_SLGigEVision_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_SLGigEVision_0000_0000_v0_0_s_ifspec;

#ifndef __ISLGigEVisionCam_INTERFACE_DEFINED__
#define __ISLGigEVisionCam_INTERFACE_DEFINED__

/* interface ISLGigEVisionCam */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISLGigEVisionCam;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("037fd175-0826-4a01-9b64-5b985c6bf5a3")
    ISLGigEVisionCam : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetImageInfo( 
            /* [out] */ LONG *oWidth,
            /* [out] */ LONG *oHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFifoInfo( 
            /* [out] */ LONG *oMinIndex,
            /* [out] */ LONG *oMaxIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImage( 
            /* [in] */ LONG iImageIndex,
            /* [in] */ eSLGEVImagePixelFormat iFormat,
            /* [size_is][out] */ BYTE *oImage,
            /* [in] */ LONG iImageSize,
            /* [out] */ double *oImageTimeInSec) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISLGigEVisionCamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISLGigEVisionCam * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISLGigEVisionCam * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISLGigEVisionCam * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetImageInfo )( 
            ISLGigEVisionCam * This,
            /* [out] */ LONG *oWidth,
            /* [out] */ LONG *oHeight);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            ISLGigEVisionCam * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFifoInfo )( 
            ISLGigEVisionCam * This,
            /* [out] */ LONG *oMinIndex,
            /* [out] */ LONG *oMaxIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            ISLGigEVisionCam * This,
            /* [in] */ LONG iImageIndex,
            /* [in] */ eSLGEVImagePixelFormat iFormat,
            /* [size_is][out] */ BYTE *oImage,
            /* [in] */ LONG iImageSize,
            /* [out] */ double *oImageTimeInSec);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            ISLGigEVisionCam * This);
        
        END_INTERFACE
    } ISLGigEVisionCamVtbl;

    interface ISLGigEVisionCam
    {
        CONST_VTBL struct ISLGigEVisionCamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISLGigEVisionCam_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISLGigEVisionCam_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISLGigEVisionCam_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISLGigEVisionCam_GetImageInfo(This,oWidth,oHeight)	\
    ( (This)->lpVtbl -> GetImageInfo(This,oWidth,oHeight) ) 

#define ISLGigEVisionCam_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define ISLGigEVisionCam_GetFifoInfo(This,oMinIndex,oMaxIndex)	\
    ( (This)->lpVtbl -> GetFifoInfo(This,oMinIndex,oMaxIndex) ) 

#define ISLGigEVisionCam_GetImage(This,iImageIndex,iFormat,oImage,iImageSize,oImageTimeInSec)	\
    ( (This)->lpVtbl -> GetImage(This,iImageIndex,iFormat,oImage,iImageSize,oImageTimeInSec) ) 

#define ISLGigEVisionCam_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISLGigEVisionCam_INTERFACE_DEFINED__ */


#ifndef __ISLGigEVisionCamInit_INTERFACE_DEFINED__
#define __ISLGigEVisionCamInit_INTERFACE_DEFINED__

/* interface ISLGigEVisionCamInit */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISLGigEVisionCamInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95C6C2C6-3C37-435D-B87B-20E6F7AF7264")
    ISLGigEVisionCamInit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ BSTR iFile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISLGigEVisionCamInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISLGigEVisionCamInit * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISLGigEVisionCamInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISLGigEVisionCamInit * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            ISLGigEVisionCamInit * This,
            /* [in] */ BSTR iFile);
        
        END_INTERFACE
    } ISLGigEVisionCamInitVtbl;

    interface ISLGigEVisionCamInit
    {
        CONST_VTBL struct ISLGigEVisionCamInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISLGigEVisionCamInit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISLGigEVisionCamInit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISLGigEVisionCamInit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISLGigEVisionCamInit_Init(This,iFile)	\
    ( (This)->lpVtbl -> Init(This,iFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISLGigEVisionCamInit_INTERFACE_DEFINED__ */


#ifndef __ISLGigEVisionMgr_INTERFACE_DEFINED__
#define __ISLGigEVisionMgr_INTERFACE_DEFINED__

/* interface ISLGigEVisionMgr */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISLGigEVisionMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18ABE099-E9B4-4E31-9B4D-A239EC511932")
    ISLGigEVisionMgr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCamCount( 
            /* [out] */ LONG *oCamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCamInfo( 
            /* [in] */ LONG iCamIndex,
            /* [out] */ LONG *oWidth,
            /* [out] */ LONG *oHeight,
            /* [out] */ double *oFPS,
            /* [out] */ BSTR *oName,
            /* [out] */ BSTR *oID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCamObject( 
            /* [in] */ LONG iCamIndex,
            /* [out] */ ISLGigEVisionCam **oISLGigEVisionCam) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISLGigEVisionMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISLGigEVisionMgr * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISLGigEVisionMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISLGigEVisionMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCamCount )( 
            ISLGigEVisionMgr * This,
            /* [out] */ LONG *oCamNumber);
        
        HRESULT ( STDMETHODCALLTYPE *GetCamInfo )( 
            ISLGigEVisionMgr * This,
            /* [in] */ LONG iCamIndex,
            /* [out] */ LONG *oWidth,
            /* [out] */ LONG *oHeight,
            /* [out] */ double *oFPS,
            /* [out] */ BSTR *oName,
            /* [out] */ BSTR *oID);
        
        HRESULT ( STDMETHODCALLTYPE *GetCamObject )( 
            ISLGigEVisionMgr * This,
            /* [in] */ LONG iCamIndex,
            /* [out] */ ISLGigEVisionCam **oISLGigEVisionCam);
        
        END_INTERFACE
    } ISLGigEVisionMgrVtbl;

    interface ISLGigEVisionMgr
    {
        CONST_VTBL struct ISLGigEVisionMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISLGigEVisionMgr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISLGigEVisionMgr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISLGigEVisionMgr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISLGigEVisionMgr_GetCamCount(This,oCamNumber)	\
    ( (This)->lpVtbl -> GetCamCount(This,oCamNumber) ) 

#define ISLGigEVisionMgr_GetCamInfo(This,iCamIndex,oWidth,oHeight,oFPS,oName,oID)	\
    ( (This)->lpVtbl -> GetCamInfo(This,iCamIndex,oWidth,oHeight,oFPS,oName,oID) ) 

#define ISLGigEVisionMgr_GetCamObject(This,iCamIndex,oISLGigEVisionCam)	\
    ( (This)->lpVtbl -> GetCamObject(This,iCamIndex,oISLGigEVisionCam) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISLGigEVisionMgr_INTERFACE_DEFINED__ */



#ifndef __SLGigEVisionLib_LIBRARY_DEFINED__
#define __SLGigEVisionLib_LIBRARY_DEFINED__

/* library SLGigEVisionLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SLGigEVisionLib;

EXTERN_C const CLSID CLSID_SLGigEVisionMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("11c57dab-9a94-4dce-9ddf-507dd66b7ab4")
SLGigEVisionMgr;
#endif

EXTERN_C const CLSID CLSID_SLGigEVisionCam;

#ifdef __cplusplus

class DECLSPEC_UUID("4E478BC3-F240-44BF-9A4B-E1CA33138AB0")
SLGigEVisionCam;
#endif
#endif /* __SLGigEVisionLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


