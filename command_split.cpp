#include <commands/impl/command_split.hpp>
#include <utils/binary_reader.hpp>
#include <fstream>

const std::string command_split::name_("split");

void command_split::execute(char** arguments)
{
  binary_reader reader(arguments[0]);
  std::string contents(reader.get_actual_file_contents());
  unsigned int width = *(unsigned int*)&contents[0x12];
  *(unsigned int*)&contents[0x12] /= 2;
  unsigned int height = *(unsigned int*)&contents[0x16];
  *(unsigned int*)&contents[0x16] /= 2;

  std::ofstream filesOut[4];
  for(int i=0;i<4;++i) filesOut[i].open(arguments[i+1], std::ios::binary);
  for(int i = 0; i < 4; ++i) filesOut[i].write(contents.c_str(), bmp_header_size_);
  for (size_t i = 0; i < width * height * 3; i += 3)
    if ((i / 3) % width < width / 2) // lewa strona
    {
      if ((i / 3) / width < height / 2) // gora
        filesOut[0].write(&contents[bmp_header_size_ + i], 3);
      else //dol
        filesOut[2].write(&contents[bmp_header_size_ + i], 3);
    }
    else //prawa
    {
      if ((i / 3) / width < height / 2) // gora
        filesOut[1].write(&contents[bmp_header_size_ + i], 3);
      else //dol
        filesOut[3].write(&contents[bmp_header_size_ + i], 3);
    }

}
