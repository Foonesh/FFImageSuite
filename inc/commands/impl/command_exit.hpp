#pragma once

#include <commands/command.hpp>

class command_exit
  : public command
{

  public:

    virtual void execute() override;

    static const std::string name_;

};

