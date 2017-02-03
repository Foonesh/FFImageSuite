#pragma once

#include <commands/command.hpp>

class command_flip
  : public command
{

  public:

    virtual void execute(int argc, char** arguments) override;

    static const std::string name_;

};

