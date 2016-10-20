#include <commands\command_factory.hpp>
#include <commands\impl\command_exit.hpp>
#include <commands\impl\command_help.hpp>

const std::map<std::string, std::function<command_factory::pointer(const std::string&)>> command_factory::factory_method_table
{
  {
    get_command_name<command_exit>(), [](const std::string & commandline)
    {
      return std::make_unique<command_exit>(commandline);
    }
  },
  {
    get_command_name<command_help>(), [](const std::string & commandline)
    {
      return std::make_unique<command_help>(commandline);
    }
  },
};

command_factory::pointer command_factory::construct(const std::string& commandline)
{

  // tu oczywisce potrzeba jakiegos tokenizera aby rozbic komende i parametry
  // aby map::at() dostal jedynie polecenie do porownania
  //temp wersja dla testu helpa i exita
  return factory_method_table.at(commandline)(commandline);
}
