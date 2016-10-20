#pragma once

#include <commands\command.hpp>

class command_exit
  : public command
{

  public:
    command_exit(const std::string& commandline) {}
    virtual void execute() override;
};

template <>
inline const std::string& get_command_name<command_exit>()
{
  static const std::string name("exit");
  return name;
}