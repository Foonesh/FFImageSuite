#include <commands/command_factory.hpp>

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "Missing command line" << std::endl;
    return 0;
  }
  {
    try
    {
      auto cmd(command_factory::construct(argv[1]));
      cmd->execute(argv + 2);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
}
