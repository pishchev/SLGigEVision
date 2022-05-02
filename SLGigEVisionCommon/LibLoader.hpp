#pragma once
#include "GenTL.h"

#include <string>

static HMODULE gentl;

static GenTL::PGCGetLastError GCGetLastError;

static GenTL::PGCInitLib GCInitLib;
static GenTL::PGCCloseLib GCCloseLib;
static GenTL::PGCGetInfo GCGetInfo;

static GenTL::PTLOpen TLOpen;
static GenTL::PTLClose TLClose;
static GenTL::PTLUpdateInterfaceList TLUpdateInterfaceList;
static GenTL::PTLGetInfo TLGetInfo;
static GenTL::PTLGetNumInterfaces TLGetNumInterfaces;
static GenTL::PTLGetInterfaceID TLGetInterfaceID;
static GenTL::PTLOpenInterface TLOpenInterface;

static GenTL::PIFUpdateDeviceList IFUpdateDeviceList;
static GenTL::PIFGetNumDevices IFGetNumDevices;
static GenTL::PIFGetDeviceID IFGetDeviceID;
static GenTL::PIFOpenDevice IFOpenDevice;
static GenTL::PIFClose IFClose;

static GenTL::PDevGetNumDataStreams DevGetNumDataStreams;
static GenTL::PDevGetDataStreamID DevGetDataStreamID;
static GenTL::PDevOpenDataStream DevOpenDataStream;
static GenTL::PDevGetPort DevGetPort;
static GenTL::PDevClose DevClose;

static GenTL::PGCGetNumPortURLs GCGetNumPortURLs;
static GenTL::PGCGetPortURLInfo GCGetPortURLInfo;
static GenTL::PGCReadPort GCReadPort;
static GenTL::PGCWritePort GCWritePort;
static GenTL::PGCRegisterEvent GCRegisterEvent;

static GenTL::PEventGetData EventGetData;

static GenTL::PDSGetBufferInfo DSGetBufferInfo;
static GenTL::PDSAnnounceBuffer DSAnnounceBuffer;

static GenTL::PDSGetInfo DSGetInfo;
static GenTL::PDSAllocAndAnnounceBuffer DSAllocAndAnnounceBuffer;

static GenTL::PGCGetPortInfo GCGetPortInfo;

static GenTL::PDSStartAcquisition DSStartAcquisition;
static GenTL::PDSStopAcquisition DSStopAcquisition;
static GenTL::PDSClose DSClose;

static GenTL::PDSQueueBuffer DSQueueBuffer;
static GenTL::PDSRevokeBuffer DSRevokeBuffer;



static void Init_Lib(std::string module_)
{
	gentl = LoadLibraryA(module_.data());
	assert(gentl != nullptr);

	GCGetLastError = (GenTL::PGCGetLastError)GetProcAddress(gentl, "GCGetLastError");
	assert(GCGetLastError != nullptr);

	GCInitLib = (GenTL::PGCInitLib)GetProcAddress(gentl, "GCInitLib");
	assert(GCInitLib != nullptr);

	GCCloseLib = (GenTL::PGCCloseLib)GetProcAddress(gentl, "GCCloseLib");
	assert(GCCloseLib != nullptr);

	GCGetInfo = (GenTL::PGCGetInfo)GetProcAddress(gentl, "GCGetInfo");
	assert(GCGetInfo != nullptr);

	TLOpen = (GenTL::PTLOpen)GetProcAddress(gentl, "TLOpen");
	assert(TLOpen != nullptr);

	TLClose = (GenTL::PTLClose)GetProcAddress(gentl, "TLClose");
	assert(TLClose != nullptr);

	TLUpdateInterfaceList = (GenTL::PTLUpdateInterfaceList)GetProcAddress(gentl, "TLUpdateInterfaceList");
	assert(TLUpdateInterfaceList != nullptr);

	TLGetInfo = (GenTL::PTLGetInfo)GetProcAddress(gentl, "TLGetInfo");
	assert(TLGetInfo != nullptr);

	TLGetNumInterfaces = (GenTL::PTLGetNumInterfaces)GetProcAddress(gentl, "TLGetNumInterfaces");
	assert(TLGetNumInterfaces != nullptr);

	TLGetInterfaceID = (GenTL::PTLGetInterfaceID)GetProcAddress(gentl, "TLGetInterfaceID");
	assert(TLGetInterfaceID != nullptr);

	TLOpenInterface = (GenTL::PTLOpenInterface)GetProcAddress(gentl, "TLOpenInterface");
	assert(TLOpenInterface != nullptr);

	IFUpdateDeviceList = (GenTL::PIFUpdateDeviceList)GetProcAddress(gentl, "IFUpdateDeviceList");
	assert(IFUpdateDeviceList != nullptr);

	IFGetNumDevices = (GenTL::PIFGetNumDevices)GetProcAddress(gentl, "IFGetNumDevices");
	assert(IFGetNumDevices != nullptr);

	IFGetDeviceID = (GenTL::PIFGetDeviceID)GetProcAddress(gentl, "IFGetDeviceID");
	assert(IFGetDeviceID != nullptr);

	IFOpenDevice = (GenTL::PIFOpenDevice)GetProcAddress(gentl, "IFOpenDevice");
	assert(IFOpenDevice != nullptr);

	IFClose = (GenTL::PIFClose)GetProcAddress(gentl, "IFClose");
	assert(IFClose != nullptr);

	DevGetNumDataStreams = (GenTL::PDevGetNumDataStreams)GetProcAddress(gentl, "DevGetNumDataStreams");
	assert(DevGetNumDataStreams != nullptr);

	DevGetDataStreamID = (GenTL::PDevGetDataStreamID)GetProcAddress(gentl, "DevGetDataStreamID");
	assert(DevGetDataStreamID != nullptr);

	DevOpenDataStream = (GenTL::PDevOpenDataStream)GetProcAddress(gentl, "DevOpenDataStream");
	assert(DevOpenDataStream != nullptr);

	DevGetPort = (GenTL::PDevGetPort)GetProcAddress(gentl, "DevGetPort");
	assert(DevGetPort != nullptr);

	DevClose = (GenTL::PDevClose)GetProcAddress(gentl, "DevClose");
	assert(DevClose != nullptr);

	GCGetNumPortURLs = (GenTL::PGCGetNumPortURLs)GetProcAddress(gentl, "GCGetNumPortURLs");
	assert(GCGetNumPortURLs != nullptr);
	
	GCGetPortURLInfo = (GenTL::PGCGetPortURLInfo)GetProcAddress(gentl, "GCGetPortURLInfo");
	assert(GCGetPortURLInfo != nullptr);

	GCReadPort = (GenTL::PGCReadPort)GetProcAddress(gentl, "GCReadPort");
	assert(GCReadPort != nullptr);

	GCRegisterEvent = (GenTL::PGCRegisterEvent)GetProcAddress(gentl, "GCRegisterEvent");
	assert(GCRegisterEvent != nullptr);

	EventGetData = (GenTL::PEventGetData)GetProcAddress(gentl, "EventGetData");
	assert(EventGetData != nullptr);

	DSGetBufferInfo = (GenTL::PDSGetBufferInfo)GetProcAddress(gentl, "DSGetBufferInfo");
	assert(DSGetBufferInfo != nullptr);

	DSAnnounceBuffer = (GenTL::PDSAnnounceBuffer)GetProcAddress(gentl, "DSAnnounceBuffer");
	assert(DSAnnounceBuffer != nullptr);

	DSGetInfo = (GenTL::PDSGetInfo)GetProcAddress(gentl, "DSGetInfo");
	assert(DSGetInfo != nullptr);

	DSAllocAndAnnounceBuffer = (GenTL::PDSAllocAndAnnounceBuffer)GetProcAddress(gentl, "DSAllocAndAnnounceBuffer");
	assert(DSAllocAndAnnounceBuffer != nullptr);

	DSStartAcquisition = (GenTL::PDSStartAcquisition)GetProcAddress(gentl, "DSStartAcquisition");
	assert(DSStartAcquisition != nullptr);

	DSStopAcquisition = (GenTL::PDSStopAcquisition)GetProcAddress(gentl, "DSStopAcquisition");
	assert(DSStopAcquisition != nullptr);

	DSClose = (GenTL::PDSClose)GetProcAddress(gentl, "DSClose");
	assert(DSClose != nullptr);

	DSQueueBuffer = (GenTL::PDSQueueBuffer)GetProcAddress(gentl, "DSQueueBuffer");
	assert(DSQueueBuffer != nullptr);

	DSRevokeBuffer = (GenTL::PDSRevokeBuffer)GetProcAddress(gentl, "DSRevokeBuffer");
	assert(DSRevokeBuffer != nullptr);

	GCWritePort = (GenTL::PGCWritePort)GetProcAddress(gentl, "GCWritePort");
	assert(GCWritePort != nullptr);

	GCGetPortInfo = (GenTL::PGCGetPortInfo)GetProcAddress(gentl, "GCGetPortInfo");
	assert(GCGetPortInfo != nullptr);
}
