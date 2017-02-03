#include <commands/impl/command_greyscale.hpp>
#include <utils/bmp_format.hpp>
#include <utils/binary_writer.hpp>

const std::string command_greyscale::name_("greyscale");

void command_greyscale::execute(int argc, char** arguments)
{
  if (argc != 2)
    throw std::invalid_argument("Greyscale has to be called with 2 arguments");
  bmp_format bmpfile(arguments[0]);
  binary_writer writer(arguments[1]);
  bmpfile.dump_header(writer.file);
  auto width = bmpfile.get_width();
  auto height = bmpfile.get_height();
  rgb** pixels = bmpfile.get_pixels();
  for (std::size_t i = 0; i < height; ++i)
  {
    for (std::size_t k = 0; k < width; ++k)
    {
      int sum = pixels[i][k].r + pixels[i][k].g + pixels[i][k].b;
      sum /= 3;
      pixels[i][k].r = (char)sum;
      pixels[i][k].g = (char)sum;
      pixels[i][k].b = (char)sum;
    }
    writer.write(pixels[i], width * sizeof(rgb));
  }
}