#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>

struct Parameter
{
  Parameter() = default;
  Parameter(const std::string& iType, const std::string& iValue) : type(iType), value(iValue) {};

  std::string type;
  std::string value;
};

typedef std::map<std::string, Parameter> NodeParameters;

class Configurator
{
public:
  
  bool ReadConfig(std::string iFileName)
  {
    std::ifstream fd("D:\\GigeVisionConfigurations\\" + iFileName);
    if (!fd.is_open())
      return false;

    std::string word;
    while (fd >> word)
    {
      if (word == "Lib")
        fd >> _lib;
      else if (word == "Interface")
        fd >> _interface;
      else if (word == "Device")
        fd >> _device;
      else if (word == "Stream")
        fd >> _stream;
      else if (word == "Name")
        fd >> _name;
      else if (word == "FPS")
        fd >> _fps;
      else if (word == "Tick(sec)")
        fd >> _tickSec;
      else {
        std::string type, value;
        fd >> type;
        fd >> value;
        _parameters[word].type = type;
        _parameters[word].value = value;
      }
    }

    fd.close();
    return true;
  }

  void SaveConfig(std::string iFileName)
  {
    _name = std::string(iFileName.begin(), iFileName.end()-4);

    std::ofstream fd;
    fd.open("D:\\GigeVisionConfigurations\\" + iFileName, 'w');

    fd << "Name " << _name << std::endl;
    fd << "FPS " << _fps << std::endl;
    fd << "Tick(sec) " << _tickSec << std::endl;
    fd << "Lib " << _lib << std::endl;
    fd << "Interface " << _interface << std::endl;
    fd << "Device " << _device << std::endl;
    fd << "Stream " << _stream << std::endl;

    for (auto it = _parameters.begin(); it != _parameters.end(); ++it)
      fd << it->first << " " << it->second.type << " " << it->second.value << std::endl;

    fd.close();
  }

  std::string _lib;
  std::string _interface;
  std::string _device;
  std::string _stream;
  std::string _name = "noName";
  double _fps = 100;
  double _tickSec = 1e-6;

  NodeParameters _parameters;
};