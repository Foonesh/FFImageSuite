#include <commands\impl\command_exit.hpp>

#include <cstdlib> // tu chyba jest exit ; O

const std::string command_exit::name_("exit");

void command_exit::execute()
{
  exit(0);
}
