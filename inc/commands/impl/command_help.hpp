#pragma once

#include <commands/command.hpp>

class command_help
  : public command
{

  public:
    command_help(const std::string& commandline) {}
    virtual void execute() override;
};

template <>
inline const std::string& get_command_name<command_help>()
{
  static const std::string name("help");
  return name;
}
