#pragma once

#include <string>

class binary_reader
{

    const std::string filepath;

  public:

    binary_reader(const std::string& filepath);

    std::string get_actual_file_contents();

}

