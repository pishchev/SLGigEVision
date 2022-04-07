#pragma once
#include "GenTL.h"
#include "LibLoader.hpp"
#include "Logger.hpp"

class Device
{
public:

	Device(GenTL::DEV_HANDLE iDevice) : _deviceHandler(iDevice) {}
	Device() = default;
	~Device()
	{
		if (_deviceHandler)
		{
			//std::cout << "~Device" << std::endl;
			//elog(DevClose(_deviceHandler), "DevClose");
		}
	}

	void SetDevice(GenTL::DEV_HANDLE iDevice)
	{
		_deviceHandler = iDevice;
	}

	uint32_t GetNumStreams()
	{
		uint32_t numStreams;
		elog(DevGetNumDataStreams(_deviceHandler, &numStreams), "DEV_Handler::GetNumStreams");
		return numStreams;
	}

	std::vector<std::string> ShowStreams()
	{
		std::vector<std::string> streams;
		for (uint32_t i = 0; i < GetNumStreams(); i++)
		{
			Buffer dsIDs(20);
			elog(DevGetDataStreamID(_deviceHandler, i, dsIDs.Convert<char>(), dsIDs.Size()), "DEV_Handler::ShowStreams");
			streams.push_back(dsIDs.Convert<char>());
		}
		return streams;
	}

	std::string GetStreamName(uint32_t iIndex)
	{
		Buffer dsIDs(20);
		elog(DevGetDataStreamID(_deviceHandler, iIndex, dsIDs.Convert<char>(), dsIDs.Size()), "DEV_Handler::ShowStreams");
		return dsIDs.Convert<char>();
	}

	GenTL::DS_HANDLE GetStream(uint32_t iNum)
	{
		Buffer dsIDs(20);
		GenTL::DS_HANDLE ds = nullptr;

		elog(DevGetDataStreamID(_deviceHandler, iNum, dsIDs.Convert<char>(), dsIDs.Size()), "DEV_Handler::GetStream");
		elog(DevOpenDataStream(_deviceHandler, dsIDs.Convert<char>(), &ds), "DEV_Handler::GetStream");

		return ds;
	}

	GenTL::PORT_HANDLE GetPort()
	{
		GenTL::PORT_HANDLE port = nullptr;
		elog(DevGetPort(_deviceHandler, &port), "DEV_Handler::GetPort");
		return port;
	}

	GenTL::DEV_HANDLE GetDevice()
	{
		return _deviceHandler;
	}


private:
	GenTL::DEV_HANDLE _deviceHandler = nullptr;
};