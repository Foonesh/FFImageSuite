#pragma once

#include <commands/command.hpp>

class command_load_bmp
  : public command
{

  public:

    virtual void execute(char** arguments) override;

    static const std::string name_;

};
