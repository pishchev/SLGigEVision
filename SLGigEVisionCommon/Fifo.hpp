
#include <memory>

class FIFO 
{
public:
  FIFO(size_t iBufferSize, size_t iCount) : _bufferSize(iBufferSize), _count(iCount)
  {
    _fifo = new unsigned char[iBufferSize * iCount];
  }

  ~FIFO()
  {
    delete[] _fifo;
  }

  void Clear() 
  {
    _min = 0;
    _max = 0;
    _cur = 0;
  }

  void PushBack(unsigned char* iNewData)
  {
    memcpy(_fifo + _cur * _bufferSize, iNewData, _bufferSize);

    ++_cur; ++_max;
    if (_cur == _count)
      _cur = 0;

    _min = _max > _count? _max - _count: 0;
  }

  void GetInfo(size_t& oMin, size_t& oMax)
  {
    oMin = _min;
    oMax = _max;
  }

  bool GetBuffer(size_t iIndex, unsigned char* oBuffer)
  {
    if (iIndex >= _max || iIndex < _min)
      return false;

    memcpy(oBuffer, _fifo + iIndex % _count * _bufferSize, _bufferSize);
    return true;
  }

  unsigned char* GetBufferPtr(size_t iIndex)
  {
    if (iIndex >= _max || iIndex < _min)
      return nullptr;

    return _fifo + iIndex % _count * _bufferSize;
  }

private:

  size_t _min;
  size_t _max;
  size_t _cur;

  size_t _bufferSize;
  size_t _count;

  unsigned char* _fifo;
};