#pragma once

#include <commands/command.hpp>

#include <memory>
#include <map>
#include <string>
#include <functional>

class command_factory
{
    using pointer = std::unique_ptr<command>;

  public:

    static pointer construct(const std::string& commandline);

    static const std::map<std::string, std::function<pointer(const std::string&)>> factory_method_table;
};
