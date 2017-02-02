#pragma once

#include <commands/command.hpp>

class command_split
  : public command
{
    static const unsigned int bmp_header_size_ = 0x36;

  public:

    virtual void execute(char** arguments) override;

    static const std::string name_;

};

