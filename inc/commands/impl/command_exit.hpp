#pragma once

#include <commands\command.hpp>

class command_exit
  : public command
{

	

  public:
    command_exit(const std::string& commandline) {}
    virtual void execute() override;
	static const std::string name_;
};