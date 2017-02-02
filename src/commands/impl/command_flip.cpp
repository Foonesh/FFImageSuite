#include <commands/impl/command_flip.hpp>
#include <utils/binary_reader.hpp>
#include <fstream>

const std::string command_flip::name_("flip");

void command_flip::execute(char** arguments)
{
  /*binary_reader reader(arguments[0]);
  std::string contents(reader.get_actual_file_contents());
  unsigned int width = *(unsigned int*)&contents[0x12];
  unsigned int height = *(unsigned int*)&contents[0x16];
  std::ofstream fileOut(arguments[1], std::ios::binary);
  fileOut.write(contents.c_str(), bmp_header_size_);
  for (size_t i = 0; i < width * height * 3; i += 3)
    fileOut.write(&contents[bmp_header_size_ + width * height * 3 - 3 - i], 3);*/
}
