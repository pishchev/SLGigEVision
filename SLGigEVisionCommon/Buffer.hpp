#pragma once
#include <iostream>
#include <typeinfo>

class Buffer
{
public:
	Buffer()
	{
		_size = 0;
		_buffer = nullptr;
	}

	Buffer(size_t iSize)
	{
		_buffer = new BYTE[iSize];
		_size = iSize;
	}

	~Buffer()
	{
		if (_buffer &&!_size)
			delete[] _buffer;
	}

	void* operator*()
	{
		return _buffer;
	}

	template <class T>
	T* Convert()
	{
		return reinterpret_cast<T*>(_buffer);
	}

	size_t* Size()
	{
		return &_size;
	}

private:
	BYTE* _buffer;
	size_t _size;
};