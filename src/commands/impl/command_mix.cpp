#include <commands/impl/command_mix.hpp>
#include <utils/bmp_format.hpp>
#include <utils/binary_writer.hpp>

const std::string command_mix::name_("mix");

void command_mix::execute(int argc, char** arguments)
{
  if (argc != 3)
    throw std::invalid_argument("Mix has to be called with 3 arguments");
  bmp_format bmpfileA(arguments[0]);
  bmp_format bmpfileB(arguments[1]);
  binary_writer writer(arguments[2]);
  auto widthA = bmpfileA.get_width();
  auto heightA = bmpfileA.get_height();
  rgb** pixelsA = bmpfileA.get_pixels();
  auto widthB = bmpfileB.get_width();
  auto heightB = bmpfileB.get_height();
  rgb** pixelsB = bmpfileB.get_pixels();
  if (widthA != widthB || heightA != heightB)
    throw std::runtime_error("Unable to mix different size bitmaps!");
  bmpfileA.dump_header(writer.file);
  for (std::size_t i = 0; i < heightA; ++i)
  {
    for (std::size_t k = 0; k < widthA; ++k)
    {
      pixelsA[i][k].r /= 2;
	  pixelsA[i][k].r += pixelsB[i][k].r / 2 - 1;
      pixelsA[i][k].g /= 2;
      pixelsA[i][k].g += pixelsB[i][k].g / 2 - 1;
      pixelsA[i][k].b /= 2;
      pixelsA[i][k].b += pixelsB[i][k].b / 2 - 1;
    }
    writer.write(pixelsA[i], widthA * sizeof(rgb));
  }
}
