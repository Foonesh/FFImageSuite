#include <commands/command_factory.hpp>
#include <commands/impl/command_exit.hpp>
#include <commands/impl/command_help.hpp>

template <typename T>
std::pair<std::string, std::function<command_factory::pointer(const std::string&)>> make_handler()
{
  return
  {
    T::name_, [](const std::string & commandline)
    {
      return std::unique_ptr<T>(new T(commandline));//std::make_unique<T>(commandline);
    }
  };
}

const std::map<std::string, std::function<command_factory::pointer(const std::string&)>> command_factory::factory_method_table
{
  make_handler<command_exit>(),
  make_handler<command_help>(),
};

command_factory::pointer command_factory::construct(const std::string& commandline)
{
  // tu oczywisce potrzeba jakiegos tokenizera aby rozbic komende i parametry
  // aby map::at() dostal jedynie polecenie do porownania
  //temp wersja dla testu helpa i exita
  return factory_method_table.at(commandline)(commandline);
}
