#include <commands\impl\command_help.hpp>
#include <commands\command_factory.hpp>

#include <iostream>

const std::string command_help::name_("help");

void command_help::execute()
{
  std::cout << "List of supported commands\n";
  for (const auto& elem : command_factory::factory_method_table)
    std::cout << elem.first << '\n';
}