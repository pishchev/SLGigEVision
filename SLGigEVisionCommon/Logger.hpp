#pragma once

#include <iostream>
#include <windows.h> 
#include <assert.h>

#include "GenTL.h"

#include "LibLoader.hpp"


static void log(GenTL::GC_ERROR iError, std::string iOperation)
{
	Buffer buff(1000);

	const auto logError = GCGetLastError(&iError, buff.Convert<char>(), buff.Size());
	if (logError != 0)
	{
		std::cout << "Logging error! Error descriptor: " << logError << std::endl;
		return;
	}

	std::cout << "log -> Operation " << iOperation << ". Status: " << buff.Convert<char>() << std::endl;

	if (iError != 0)
	{
		std::cout << "Error code: " << iError << std::endl;
		system("pause");
		exit(-1);
	}
}

static void elog(GenTL::GC_ERROR iError, std::string iOperation)
{
	if (iError != 0)
		log(iError, iOperation);
}


