#include <commands/impl/command_rotate.hpp>
#include <utils/bmp_format.hpp>
#include <utils/binary_writer.hpp>

const std::string command_rotate::name_("rotate");

void command_rotate::execute(int argc, char** arguments)
{
  if (argc != 2)
    throw std::invalid_argument("Rotate has to be called with 2 arguments");
  bmp_format bmpfile(arguments[0]);
  binary_writer writer(arguments[1]);
  auto width = bmpfile.get_width();
  auto height = bmpfile.get_height();
  rgb** pixels = bmpfile.get_pixels();
  bmpfile.dump_header(writer.file, height, width);
  for (std::size_t i = 0; i < width; ++i)
    for (size_t k = 0; k < height; ++k)
      writer.write((void*)&pixels[height - 1 - k][i], sizeof(rgb));
}
