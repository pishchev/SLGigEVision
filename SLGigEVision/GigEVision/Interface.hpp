#pragma once
#include "GenTL.h"
#include "LibLoader.hpp"
#include "Logger.hpp"

class Interface
{
public:
	Interface(GenTL::IF_HANDLE iInterface) : _interfaceHandler(iInterface) {}

	Interface(){}
	~Interface()
	{
		if (_interfaceHandler)
		{
			//std::cout << "~Interface" << std::endl;
			//elog(IFClose(_interfaceHandler), "IFClose");
		}
	}

	void SetInterfaces(GenTL::IF_HANDLE iInterface)
	{
		_interfaceHandler = iInterface;
	}

	void UpdateDeviceList()
	{
		elog(IFUpdateDeviceList(_interfaceHandler, nullptr, 1000), "IF_Handler::UpdateInterfaceList");
	}

	uint32_t GetNumDevices()
	{
		uint32_t numDevices;
		elog(IFGetNumDevices(_interfaceHandler, &numDevices), "IF_Handler::GetNumDevices");
		return numDevices;
	}

	std::string GetDeviceName(uint32_t iIndex) {
		Buffer buffer(60);
		elog(IFGetDeviceID(_interfaceHandler, iIndex, (char*)buffer.Convert<char>(), buffer.Size()), "IF_Handler::ShowDevices");
		return buffer.Convert<char>();
	}

	GenTL::DEV_HANDLE GetDevice(uint32_t iIndex)
	{
		Buffer buffer(60);
		GenTL::DEV_HANDLE hDevice = nullptr;

		elog(IFGetDeviceID(_interfaceHandler, iIndex, (char*)buffer.Convert<char>(), buffer.Size()), "IF_Handler::GetDevice");
		elog(IFOpenDevice(_interfaceHandler, buffer.Convert<char>(), GenTL::DEVICE_ACCESS_EXCLUSIVE, &hDevice), "IF_Handler::GetDevice");

		return hDevice;
	}

	GenTL::IF_HANDLE GetInterface()
	{
		return _interfaceHandler;
	}

private:
	GenTL::IF_HANDLE _interfaceHandler = nullptr;
};