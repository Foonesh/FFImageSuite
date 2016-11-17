#include <commands/command_factory.hpp>
#include <commands/impl/command_exit.hpp>
#include <commands/impl/command_help.hpp>
#include <commands/impl/command_load_bmp.hpp>

template <typename T>
std::pair<std::string, command_factory::factory_method> make_handler()
{
  return
  {
    T::name_, []()
    {
      return std::unique_ptr<T>(new T());//std::make_unique<T>(commandline);
    }
  };
}

command_factory::pointer command_factory::construct(const std::string& commandline)
{
  // tu oczywisce potrzeba jakiegos tokenizera aby rozbic komende i parametry
  // aby map::at() dostal jedynie polecenie do porownania
  //temp wersja dla testu helpa i exita
  return get_command_dictionary().at(commandline)();
}

const command_factory::dictionary& command_factory::get_command_dictionary()
{
  static const std::map<std::string, std::function<command_factory::pointer()>> factory_method_table
  {
    make_handler<command_exit>(),
    make_handler<command_help>(),
    make_handler<command_load_bmp>(),
  };
  return factory_method_table;
}
