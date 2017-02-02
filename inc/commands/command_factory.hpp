#pragma once

#include <commands/command.hpp>

#include <memory>
#include <map>
#include <string>
#include <functional>

class command_factory
{

  public:

    using pointer = std::unique_ptr<command>;
    using factory_method = std::function<pointer()>;
    using dictionary = std::map<std::string, factory_method>;

    static pointer construct(const char* command_name);

    static const dictionary& get_command_dictionary();
};
