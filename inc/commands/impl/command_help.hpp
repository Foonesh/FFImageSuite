#pragma once

#include <commands/command.hpp>

class command_help
  : public command
{
	

  public:
    command_help(const std::string& commandline) {}
    virtual void execute() override;
<<<<<<< HEAD
	static const std::string name_;
};
=======
};

template <>
inline const std::string& get_command_name<command_help>()
{
  static const std::string name("help");
  return name;
}
>>>>>>> 31179f1ce637fcd1dd94fb3b092ddf1050d8137f
