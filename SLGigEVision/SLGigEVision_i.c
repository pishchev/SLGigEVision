

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ISLGigEVisionCam,0x037fd175,0x0826,0x4a01,0x9b,0x64,0x5b,0x98,0x5c,0x6b,0xf5,0xa3);


MIDL_DEFINE_GUID(IID, IID_ISLGigEVisionCamInit,0x95C6C2C6,0x3C37,0x435D,0xB8,0x7B,0x20,0xE6,0xF7,0xAF,0x72,0x64);


MIDL_DEFINE_GUID(IID, IID_ISLGigEVisionMgr,0x18ABE099,0xE9B4,0x4E31,0x9B,0x4D,0xA2,0x39,0xEC,0x51,0x19,0x32);


MIDL_DEFINE_GUID(IID, LIBID_SLGigEVisionLib,0x07277cb7,0xd484,0x433a,0xa2,0x26,0xbc,0x5c,0xf6,0x76,0xff,0x0a);


MIDL_DEFINE_GUID(CLSID, CLSID_SLGigEVisionMgr,0x11c57dab,0x9a94,0x4dce,0x9d,0xdf,0x50,0x7d,0xd6,0x6b,0x7a,0xb4);


MIDL_DEFINE_GUID(CLSID, CLSID_SLGigEVisionCam,0x4E478BC3,0xF240,0x44BF,0x9A,0x4B,0xE1,0xCA,0x33,0x13,0x8A,0xB0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



