#include <commands/impl/command_greyscale.hpp>
#include <utils/binary_reader.hpp>
#include <fstream>

const std::string command_greyscale::name_("greyscale");

void command_greyscale::execute(char** arguments)
{
  binary_reader reader(arguments[0]);
  std::string contents(reader.get_actual_file_contents());
  unsigned int width = *(unsigned int*)&contents[0x12];
  unsigned int height = *(unsigned int*)&contents[0x16];
  std::ofstream fileOut(arguments[1], std::ios::binary);
  fileOut.write(contents.c_str(), bmp_header_size_);
  for (size_t i = 0; i < width * height * 3; i += 3)
  {
    int summed_color = ((int)contents[bmp_header_size_ + i] +
                        (int)contents[bmp_header_size_ + i + 1] +
                        (int)contents[bmp_header_size_ + i + 2]) / 3;
    for(int k = 0; k < 3; k++) fileOut.write((char*)&summed_color, 1);

  }
}