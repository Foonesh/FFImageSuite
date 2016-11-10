#include <utils/binary_reader.hpp>

#include <fstream>
#include <sstream>

binary_reader::binary_reader(const std::string& filepath)
  :filepath(filepath)
{
}

std::string binary_reader::get_actual_file_contents()
{
  std::ifstream in(filepath, std::ios::binary);
  if(!in) throw std::runtime_error(filepath + " cannot be opened!");
  std::stringstream stream;
  stream<<in.rdbuf();
  return stream.str();
}

