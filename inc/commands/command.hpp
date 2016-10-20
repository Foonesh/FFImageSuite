#pragma once

#include <string>

class command
{
  public:
    virtual void execute() = 0;
    virtual ~command() = default;
  protected:
    //tu wyladuje jakas klasa z mozgiem i konstruktor z command line
};

template <typename T>
const std::string& get_command_name();