#include <commands/impl/command_flip.hpp>
#include <utils/bmp_format.hpp>
#include <utils/binary_writer.hpp>

const std::string command_flip::name_("flip");

void command_flip::execute(int argc, char** arguments)
{
  if (argc != 2)
    throw std::invalid_argument("Flip has to be called with 2 arguments");
  bmp_format bmpfile(arguments[0]);
  binary_writer writer(arguments[1]);
  bmpfile.dump_header(writer.file);
  auto width = bmpfile.get_width();
  auto height = bmpfile.get_height();
  rgb** pixels = bmpfile.get_pixels();
  for (std::size_t i = 0; i < height; ++i)
    writer.write(pixels[height - 1 - i], width * sizeof(rgb));
}
