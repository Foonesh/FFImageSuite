#include <commands/impl/command_exit.hpp>

#include <cstdlib>

const std::string command_exit::name_("exit");

void command_exit::execute(int argc, char** arguments)
{
  exit(0);
}
