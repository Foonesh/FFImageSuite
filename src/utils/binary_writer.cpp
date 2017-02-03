#include <utils/binary_writer.hpp>

#include <stdexcept>

binary_writer::binary_writer(const std::string& filepath)
  : file(filepath, std::ios::binary)
{
  if(!file)
    throw std::runtime_error(filepath + " cannot be opened!");
}

void binary_writer::write(void* data, std::size_t size)
{
  file.write((char*)data, size);
}
