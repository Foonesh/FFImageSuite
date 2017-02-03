#include <commands/impl/command_load_bmp.hpp>
#include <utils/bmp_format.hpp>
#include <iostream>

const std::string command_load_bmp::name_("load_bmp");

void command_load_bmp::execute(int argc, char** arguments)
{
  bmp_format file(arguments[0]);
  std::cout << "The file is valid. Width x height = " << file.get_width() << " x " << file.get_height() << std::endl;
}
