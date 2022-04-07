#pragma once
#include <vector>
#include <memory>

class Converter;
class Raw;
class Bayer_RGB24_Interpolated;
class Bayer_RGB24_NoInterpolated;
class Bayer_UYVY_Interpolated;
class Bayer_UYVY_NoInterpolated;

typedef std::shared_ptr<Converter> ConverterPtr;
typedef std::shared_ptr<Raw> RawPtr;
typedef std::shared_ptr<Bayer_RGB24_Interpolated> Bayer_RGB24_InterpolatedPtr;
typedef std::shared_ptr<Bayer_RGB24_NoInterpolated> Bayer_RGB24_NoInterpolatedPtr;
typedef std::shared_ptr<Bayer_UYVY_Interpolated> Bayer_UYVY_InterpolatedPtr;
typedef std::shared_ptr<Bayer_UYVY_NoInterpolated> Bayer_UYVY_NoInterpolatedPtr;

enum class ConverterType {
  Raw,
  Bayer_RGB24_Int,
  Bayer_RGB24_NoInt,
  Bayer_UYVY_Int,
  Bayer_UYVY_NoInt,
};

class Converter {
public:
  enum PixType {
    R,
    G,
    B
  };

  unsigned char GetRawPixel(int h, int w) {
    if (h < 0 || h >= static_cast<int>(_height) || w < 0 || w >= static_cast<int>(_width))
      return 0;
    return _buffer[h * _width + w];
  }
  
  unsigned char GetIntPixel(int h, int w, PixType t) {
    const auto lt = h % 2 == 1 ? B : R;
    const auto pt = w % 2 == 0 ? G : lt;

    auto b = [&](int h, int w) {return GetRawPixel(h, w); };

    if (t == G) {
      if (pt == G)
        return (b(h, w) + b(h + 1, w + 1) + b(h - 1, w + 1) + b(h + 1, w - 1) + b(h - 1, w - 1)) / 5;
      else
        return (b(h, w + 1) + b(h, w - 1) + b(h + 1, w) + b(h - 1, w)) / 4;
    }
    else if (lt == t) {
      if (pt == t) {
        return b(h, w);
      }
      else {
        return (b(h, w + 1) + b(h, w - 1)) / 2;
      }
    }
    else {
      if (pt == G) {
        return (b(h + 1, w) + b(h + 1, w)) / 2;
      }
      else {
        return (b(h + 1, w + 1) + b(h - 1, w + 1) + b(h + 1, w - 1) + b(h - 1, w - 1)) / 4;
      }
    }

    return 0;
  }
  unsigned char GetNoIntPixel(int h, int w, PixType t) {
    const auto lt = h % 2 == 0 ? R : B;
    const auto pt = w % 2 == 0 ? G : lt;

    auto b = [&](int h, int w) {return GetRawPixel(h, w); };

    if (t == G) {
      if (pt == G)
        return b(h, w);
      else if (lt == R)
        return b(h, w - 1);
      else
        return b(h, w + 1);
    }
    else if (t == R) {
      if (pt == t)
        return b(h, w);
      else if (pt == B)
        return b(h + 1, w + 1);
      else if (lt == R)
        return b(h, w + 1);
      else
        return b(h + 1, w);
    }
    else {
      if (pt == B)
        return b(h, w);
      else if (pt == R)
        return b(h - 1, w - 1);
      else if (lt == R)
        return b(h - 1, w);
      else
        return b(h, w - 1);
    }

    return 0;
  }
  
  virtual void Convert(unsigned char* oBuffer) = 0;
  virtual ConverterType GetType() = 0;

  size_t _width;
  size_t _height;
  unsigned char* _buffer;
};


//RAW
class Raw : public Converter {
public:
  void Convert(unsigned char* oBuffer) override {
    memcpy(oBuffer, _buffer, _width * _height);
  }
  ConverterType GetType() override {
    return ConverterType::Raw;
  }
};


//UYUV
class BayerConverterUYVY : public Converter {
public:
  virtual unsigned char GetPixel(int h, int w, PixType t) = 0;
  virtual void Convert(unsigned char* oBuffer) override {
    for (size_t h = 0; h < _height; ++h)
      for (size_t w = 0; w < _width / 2; ++w) {

        const auto r = GetPixel((int)h, (int)w * 2, R);
        const auto g1 = GetPixel((int)h, (int)w * 2, G);
        const auto b = GetPixel((int)h, (int)w * 2, B);
        const auto g2 = GetPixel((int)h, (int)w * 2 + 1, R);

        const auto y0 = unsigned char(0.299 * r + 0.587 * g1 + 0.114 * b);
        const auto u = unsigned char(0.492 * (b - y0));
        const auto v = unsigned char(0.877 * (r - y0));
        const auto y1 = unsigned char(0.299 * r + 0.587 * g2 + 0.114 * b);

        oBuffer[h * _width * 2 + w * 4] = u;
        oBuffer[h * _width * 2 + w * 4 + 1] = y0;
        oBuffer[h * _width * 2 + w * 4 + 2] = v;
        oBuffer[h * _width * 2 + w * 4 + 3] = y1;
      }
  };
};

class Bayer_UYVY_Interpolated : public BayerConverterUYVY {
public:
  virtual unsigned char GetPixel(int h, int w, PixType t) override {
    return GetIntPixel(h, w, t);
  }
  ConverterType GetType() override {
    return ConverterType::Bayer_UYVY_Int;
  }
};

class Bayer_UYVY_NoInterpolated : public BayerConverterUYVY {
public:
  virtual unsigned char GetPixel(int h, int w, PixType t) override {
    return GetNoIntPixel(h, w, t);
  }
  ConverterType GetType() override {
    return ConverterType::Bayer_UYVY_NoInt;
  }
};


//RGB
class BayerConverterRGB : public Converter {
public:
  virtual unsigned char GetPixel(int h, int w, PixType t) = 0;
  virtual void Convert(unsigned char* oBuffer) override {

    for (size_t h = 0; h < _height; ++h)
      for (size_t w = 0; w < _width; ++w) {
        oBuffer[h * _width * 3 + w * 3] = GetPixel((int)h, (int)w, R);
        oBuffer[h * _width * 3 + w * 3 + 1] = GetPixel((int)h, (int)w, G);
        oBuffer[h * _width * 3 + w * 3 + 2] = GetPixel((int)h, (int)w, B);
      }
  }
};

class Bayer_RGB24_Interpolated : public BayerConverterRGB {
public:
  virtual unsigned char GetPixel(int h, int w, PixType t) override {
    return GetIntPixel(h, w, t);
  }
  ConverterType GetType() override {
    return ConverterType::Bayer_RGB24_Int;
  }
};

class Bayer_RGB24_NoInterpolated : public BayerConverterRGB {
public:
  virtual unsigned char GetPixel(int h, int w, PixType t) override {
    return GetNoIntPixel(h, w, t);
  }
  ConverterType GetType() override {
    return ConverterType::Bayer_RGB24_NoInt;
  }
};