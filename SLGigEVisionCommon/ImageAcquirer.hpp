#pragma once

#include "Buffer.hpp"
#include <vector>
#include "GenTL.h"
#include "Logger.hpp"

class ImageAcquirer
{
public:
	void AnnounceBuffers(GenTL::DS_HANDLE iStream , size_t iPayloadSize)
	{
		int type = 1;
		Buffer numBuffers(20);
		auto const err = DSGetInfo(iStream, GenTL::STREAM_INFO_BUF_ANNOUNCE_MIN, &type, numBuffers.Convert<char>(), numBuffers.Size());

		if (err!=0)
			_buffers = std::vector<GenTL::BUFFER_HANDLE>(1, nullptr);
		else
			_buffers = std::vector<GenTL::BUFFER_HANDLE>(*(numBuffers.Convert<size_t>()), nullptr);

		for (auto it = _buffers.begin(); it != _buffers.end(); ++it)
			elog(DSAllocAndAnnounceBuffer(iStream, iPayloadSize, nullptr, &(*it)), "DSAllocAndAnnounceBuffer");

		for (auto it = _buffers.begin(); it != _buffers.end(); ++it)
			elog(DSQueueBuffer(iStream, *it), "DSQueueBuffer");
	}

	void StartAcquisition(GenTL::DS_HANDLE hDS)
	{
		elog(DSStartAcquisition(hDS, GenTL::ACQ_START_FLAGS_DEFAULT, GENTL_INFINITE), "DSStartAcquisition");
	}

	std::vector<GenTL::BUFFER_HANDLE> GetBuffers()
	{
		return _buffers;
	}

private:
	std::vector<GenTL::BUFFER_HANDLE> _buffers;
};