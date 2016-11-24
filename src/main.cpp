#include <commands/command_factory.hpp>

#include <iostream>
#include <stdexcept>

int main(void)
{
  std::string line;
  while(std::cin >> line)
  {
    try
    {
      auto cmd(command_factory::construct(line));
      cmd->execute();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
}
