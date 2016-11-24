#include <commands/impl/command_load_bmp.hpp>
#include <utils/binary_reader.hpp>
#include <iostream>
#include <stdexcept>

const std::string command_load_bmp::name_("load_bmp");

void command_load_bmp::execute()
{
  std::string bmp_name;
  std::cin>>bmp_name;
  binary_reader reader(bmp_name);
  std::string contents(reader.get_actual_file_contents());
  if(contents.size() < bmp_header_size_)
    throw std::runtime_error("File is malformed, missing header");
  if(contents[0]!=0x42 || contents[1]!=0x4D)
    throw std::runtime_error("File is malformed, magic number is wrong");
  unsigned int filesize = *(unsigned int*)&contents[2];
  if(filesize != contents.size())
    throw std::runtime_error("Size from header does not match actual file size");
  unsigned int width = *(unsigned int*)&contents[0x12];
  unsigned int height = *(unsigned int*)&contents[0x16];
  std::cout<<"width/height "<<width<<' '<<height<<std::endl;
  for(int i=0;i<width*height;i+=3)
  {
    std::cout<<(int)contents[bmp_header_size_ + i] <<' '
    <<(int)contents[bmp_header_size_ + i + 1]<<' '
    <<(int)contents[bmp_header_size_ + i + 2]<<std::endl;
  }
}