#pragma once

#include <commands/command.hpp>

class command_exit
  : public command
{

	

  public:
    command_exit(const std::string& commandline) {}
    virtual void execute() override;
<<<<<<< HEAD
	static const std::string name_;
};
=======
};

template <>
inline const std::string& get_command_name<command_exit>()
{
  static const std::string name("exit");
  return name;
}
>>>>>>> 31179f1ce637fcd1dd94fb3b092ddf1050d8137f
