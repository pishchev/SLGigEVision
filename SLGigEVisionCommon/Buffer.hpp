#pragma once
#include <iostream>
#include <typeinfo>

class Buffer
{
public:
	Buffer()
	{
		_size = 0;
	}

	Buffer(size_t iSize)
	{
		_buffer.resize(iSize);
		_size = iSize;
	}

	void* operator*()
	{
		return _buffer.data();
	}

	template <class T>
	T* Convert()
	{
		return reinterpret_cast<T*>(_buffer.data());
	}

	size_t* Size()
	{
		return &_size;
	}

private:
	std::string _buffer;
	size_t _size;
};