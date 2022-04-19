#pragma once
#include <vector>
#include <memory>

class Converter;
class Raw;
class Bayer_RGB24_NoInterpolated;
class Bayer_UYVY_NoInterpolated;
class Bayer_BGRA_NoInterpolated;

typedef std::shared_ptr<Converter> ConverterPtr;
typedef std::shared_ptr<Raw> RawPtr;
typedef std::shared_ptr<Bayer_RGB24_NoInterpolated> Bayer_RGB24_NoInterpolatedPtr;
typedef std::shared_ptr<Bayer_UYVY_NoInterpolated> Bayer_UYVY_NoInterpolatedPtr;
typedef std::shared_ptr<Bayer_BGRA_NoInterpolated> Bayer_BGRA_NoInterpolatedPtr;

enum class ConverterType {
  Raw,
  Bayer_RGB24_NoInt,
  Bayer_UYVY_NoInt,
  Bayer_BGRA_NoInt
};

class Converter {
public:
  virtual void Convert(unsigned char* oBuffer) = 0;
  virtual ConverterType GetType() = 0;

  size_t _width;
  size_t _height;
  unsigned char* _buffer;
};


class Raw : public Converter {
public:
  void Convert(unsigned char* oBuffer) override {
    memcpy(oBuffer, _buffer, _width * _height);
  }
  ConverterType GetType() override {
    return ConverterType::Raw;
  }
};

// -------------- YUV <--> RGB ------------------- //
// !!!!!!! 0..255 RGB <--> 16..240 YUV !!!!!!!
inline BYTE ByteOf(int n) {
  if (n < 0)  return BYTE(0);
  else if (n > 255)  return BYTE(255);
  else return BYTE(n);
}
//
inline double Cy(double r, double g, double b) // Y
{
  return 16.0 + 0.257 * r + 0.504 * g + 0.098 * b;
}
inline double Cb(double r, double g, double b) // U
{
  return 128.0 - 0.148 * r - 0.291 * g + 0.439 * b;
}
inline double Cr(double r, double g, double b) // V
{
  return 128.0 + 0.439 * r - 0.368 * g - 0.071 * b;
}
//
inline void RGB2YUV(BYTE R, BYTE G, BYTE B, BYTE& Y, BYTE& U, BYTE& V)
{
  register double rf, gf, bf;
  rf = double(R);  bf = double(B);  gf = double(G);
  Y = ByteOf(int(Cy(rf, gf, bf) + 0.5));
  U = ByteOf(int(Cb(rf, gf, bf) + 0.5));
  V = ByteOf(int(Cr(rf, gf, bf) + 0.5));
}

class Bayer_UYVY_NoInterpolated : public Converter {
public:
  void Convert(unsigned char* oBuffer) override {
    size_t oStride = _width * 2;
    size_t iStride = _width;
    unsigned char* oPtr0 = oBuffer;
    unsigned char* oPtr1 = oBuffer + oStride;
    unsigned char* iPtr0 = _buffer;
    unsigned char* iPtr1 = _buffer + iStride;
    for (size_t y = 0; y < _height; y += 2) {
      for (size_t x = 0; x < _width; x += 2) {

        unsigned char nR = iPtr0[x + 0];
        unsigned char nG0 = iPtr0[x + 1];
        unsigned char nB = iPtr1[x + 0];
        unsigned char nG1 = iPtr1[x + 1];
        unsigned char u1, y1, v1, u2, y2, v2;

        RGB2YUV(nR, nG0, nB, y1, u1, v1);
        RGB2YUV(nR, nG1, nB, y2, u2, v2);

        oPtr0[x * 2 + 0] = u1;
        oPtr0[x * 2 + 1] = y1;
        oPtr0[x * 2 + 2] = v1;
        oPtr0[x * 2 + 3] = y1;
        oPtr1[x * 2 + 0] = u2;
        oPtr1[x * 2 + 1] = y2;
        oPtr1[x * 2 + 2] = v2;
        oPtr1[x * 2 + 3] = y2;
      }
      oPtr0 += oStride * 2;
      oPtr1 += oStride * 2;
      iPtr0 += iStride * 2;
      iPtr1 += iStride * 2;
    }
  }
  ConverterType GetType() override {
    return ConverterType::Bayer_UYVY_NoInt;
  }
};

class Bayer_RGB24_NoInterpolated : public Converter {
public:
  void Convert(unsigned char* oBuffer) override {
    size_t oStride = _width * 3;
    size_t iStride = _width;
    unsigned char* oPtr0 = oBuffer;
    unsigned char* oPtr1 = oBuffer + oStride;
    unsigned char* iPtr0 = _buffer;
    unsigned char* iPtr1 = _buffer + iStride;
    for (size_t y = 0; y < _height; y += 2) {
      for (size_t x = 0; x < _width; x += 2) {

        unsigned char nR = iPtr0[x + 0];
        unsigned char nG0 = iPtr0[x + 1];
        unsigned char nB = iPtr1[x + 0];
        unsigned char nG1 = iPtr1[x + 1];

        int tmpX = x * 3;
        oPtr0[tmpX + 0] = nR;
        oPtr0[tmpX + 1] = nG0;
        oPtr0[tmpX + 2] = nB;
        oPtr0[tmpX + 3] = nR;
        oPtr0[tmpX + 4] = nG0;
        oPtr0[tmpX + 5] = nB;
        oPtr1[tmpX + 0] = nR;
        oPtr1[tmpX + 1] = nG1;
        oPtr1[tmpX + 2] = nB;
        oPtr1[tmpX + 3] = nR;
        oPtr1[tmpX + 4] = nG1;
        oPtr1[tmpX + 5] = nB;
      }
      oPtr0 += oStride * 2;
      oPtr1 += oStride * 2;
      iPtr0 += iStride * 2;
      iPtr1 += iStride * 2;
    }
  }
  ConverterType GetType() override {
    return ConverterType::Bayer_RGB24_NoInt;
  }
};

class Bayer_BGRA_NoInterpolated : public Converter {
public:
	void Convert(unsigned char* oBuffer) override {
		size_t oStride = _width * 4;
		size_t iStride = _width;
		unsigned char * oPtr0 = oBuffer;
		unsigned char * oPtr1 = oBuffer + oStride;
		unsigned char * iPtr0 = _buffer;
		unsigned char * iPtr1 = _buffer + iStride;
		for (size_t y = 0; y < _height; y += 2) {
			for (size_t x = 0; x < _width; x += 2) {
				// read RGB data
				unsigned char nR = iPtr0[x + 0];
				unsigned char nG0 = iPtr0[x + 1];
				unsigned char nB = iPtr1[x + 0];
				unsigned char nG1 = iPtr1[x + 1];
				// write RGB data
				oPtr0[x * 4 + 0] = nB;
				oPtr0[x * 4 + 1] = nG0;
				oPtr0[x * 4 + 2] = nR;
				oPtr0[x * 4 + 3] = 255;
				oPtr0[x * 4 + 4] = nB;
				oPtr0[x * 4 + 5] = nG0;
				oPtr0[x * 4 + 6] = nR;
				oPtr0[x * 4 + 7] = 255;
				oPtr1[x * 4 + 0] = nB;
				oPtr1[x * 4 + 1] = nG1;
				oPtr1[x * 4 + 2] = nR;
				oPtr1[x * 4 + 3] = 255;
				oPtr1[x * 4 + 4] = nB;
				oPtr1[x * 4 + 5] = nG1;
				oPtr1[x * 4 + 6] = nR;
				oPtr1[x * 4 + 7] = 255;
			}
			oPtr0 += oStride * 2;
			oPtr1 += oStride * 2;
			iPtr0 += iStride * 2;
			iPtr1 += iStride * 2;
		}
	}
	ConverterType GetType() override {
		return ConverterType::Bayer_BGRA_NoInt;
	}
};
