#pragma once

#include "LibLoader.hpp"
#include "GenICam.h"
#include "Buffer.hpp"
#include <algorithm>

GENICAM_INTERFACE GENAPI_DECL_ABSTRACT Port : public GENAPI_NAMESPACE::IPort
{
	GenTL::PORT_HANDLE _portHandler = nullptr;

	void UsePort(GenTL::PORT_HANDLE iPort)
	{
		_portHandler = iPort;
	}

	//! Reads a chunk of bytes from the port
	virtual void Read(void* pBuffer, int64_t Address, int64_t Length)
	{
		size_t len = Length;
		elog(GCReadPort(_portHandler, Address, pBuffer , &len), "GCReadPort");
	}

	//! Writes a chunk of bytes to the port
	virtual void Write(const void* pBuffer, int64_t Address, int64_t Length)
	{
		size_t len = Length;
		elog(GCWritePort(_portHandler, Address, pBuffer, &len),"GCWritePort");
	}

	//! Get the access mode of the node
	virtual GENAPI_NAMESPACE::EAccessMode GetAccessMode() const
	{
		int type = 1;

		Buffer read(10);
		elog(GCGetPortInfo(_portHandler, GenTL::PORT_INFO_ACCESS_READ, &type, read.Convert<void>(), read.Size()), "GetAccessMode");

		Buffer write(10);
		elog(GCGetPortInfo(_portHandler, GenTL::PORT_INFO_ACCESS_WRITE, &type, write.Convert<void>(), write.Size()), "GetAccessMode");

		Buffer na(10);
		elog(GCGetPortInfo(_portHandler, GenTL::PORT_INFO_ACCESS_NA, &type, na.Convert<void>(), na.Size()), "GetAccessMode");

		Buffer ni(10);
		elog(GCGetPortInfo(_portHandler, GenTL::PORT_INFO_ACCESS_NI, &type, ni.Convert<void>(), ni.Size()), "GetAccessMode");

		if (*read.Convert<bool8_t>() && *write.Convert<bool8_t>())	return GENAPI_NAMESPACE::EAccessMode::RW;
		if (*read.Convert<bool8_t>())																return GENAPI_NAMESPACE::EAccessMode::RO;
		if (*write.Convert<bool8_t>())															return GENAPI_NAMESPACE::EAccessMode::WO;
		if (*na.Convert<bool8_t>())																	return GENAPI_NAMESPACE::EAccessMode::NA;

		return GENAPI_NAMESPACE::EAccessMode::NI;
	}

	static Buffer GetXML(GenTL::PORT_HANDLE iPort, bool& oIsZipped)
	{
		Buffer info(80);
		int32_t infoCmd = GenTL::INFO_DATATYPE_STRINGLIST;
		elog(GCGetPortURLInfo(iPort, 0, GenTL::URL_INFO_URL, &infoCmd, info.Convert<void>(), info.Size()), "GCGetPortURLInfo");
		//std::cout << info.Convert<char>() << std::endl; //информация о формате;адресе;размере XML конфигуратора

		std::string urlInfo(info.Convert<char>());
		std::replace(urlInfo.begin(), urlInfo.end(), ';', ' ');
		std::stringstream strStream(urlInfo);

		std::string fileName;
		strStream >> fileName;
		if (std::string(fileName.end() - 4, fileName.end()) == ".zip")
			oIsZipped = true;

		std::string addressStr;
		strStream >> addressStr;

		std::string sizeStr;
		strStream >> sizeStr;

		auto strHexToUint64_t = [](const std::string hex)->uint64_t {
			std::stringstream stream;
			uint64_t num;
			stream << std::hex << hex;
			stream >> num;
			return num;
		};

		uint64_t address = strHexToUint64_t(addressStr);
		uint64_t len = strHexToUint64_t(sizeStr);

		Buffer xmlData(len);
		elog(GCReadPort(iPort, address, xmlData.Convert<void>(), xmlData.Size()), "GCReadPort");

		return xmlData;
	}
};

