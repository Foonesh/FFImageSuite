#pragma once

#include <commands/command.hpp>

class command_split
  : public command
{

  public:

    virtual void execute(char** arguments) override;

    static const std::string name_;

};

