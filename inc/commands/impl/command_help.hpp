#pragma once

#include <commands\command.hpp>

class command_help
  : public command
{
	

  public:
    command_help(const std::string& commandline) {}
    virtual void execute() override;
	static const std::string name_;
};