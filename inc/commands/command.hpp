#pragma once

#include <string>

class command
{
  public:
    virtual void execute(int argc, char** arguments) = 0;
    virtual ~command() = default;
  protected:
    //tu wyladuje jakas klasa z mozgiem i konstruktor z command line
};