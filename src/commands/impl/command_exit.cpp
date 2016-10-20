#include <commands\impl\command_exit.hpp>

#include <cstdlib> // tu chyba jest exit ; O

void command_exit::execute()
{
  exit(0);
}
