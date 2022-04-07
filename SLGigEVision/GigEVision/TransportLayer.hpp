#pragma once
#include "GenTL.h"
#include "LibLoader.hpp"
#include "Logger.hpp"

class TransportLayer
{
public:

	void Open()
	{
		elog(TLOpen(&_transportHandler), "TL_Handler::Open");
	}

	~TransportLayer()
	{
		if (_transportHandler)
		{
			//std::cout << "~TransportLayer" << std::endl;
			//elog(TLClose(_transportHandler), "TL_Handler::Close");
		}
	}

	void UpdateInterfaceList()
	{
		elog(TLUpdateInterfaceList(_transportHandler, nullptr, GENTL_INFINITE), "TL_Handler::UpdateInterfaceList");
	}

	uint32_t GetNumInterfaces()
	{
		uint32_t numIterfaces = 0;
		elog(TLGetNumInterfaces(_transportHandler, &numIterfaces), "TL_Handler::GetNumInterfaces");
		return numIterfaces;
	}

	std::string GetInterfaceName(uint32_t iIndex)
	{
		Buffer buffer(80);
		elog(TLGetInterfaceID(_transportHandler, iIndex, (char*)buffer.Convert<char>(), buffer.Size()), "TL_Handler::ShowInterfaces");
		return buffer.Convert<char>();
	}

	GenTL::IF_HANDLE GetInterface(uint32_t iIndex)
	{
		Buffer buffer(80);
		GenTL::IF_HANDLE interfaceHandler = nullptr;

		elog(TLGetInterfaceID(_transportHandler, iIndex, (char*)buffer.Convert<char>(), buffer.Size()), "TL_Handler::GetInterface");
		elog(TLOpenInterface(_transportHandler, (char*)buffer.Convert<char>(), &interfaceHandler), "TL_Handler::GetInterface");

		return interfaceHandler;
	}

	GenTL::TL_HANDLE GetTL()
	{
		return _transportHandler;
	}

private:
	GenTL::TL_HANDLE _transportHandler = nullptr;
};