#include <commands/impl/command_merge.hpp>
#include <utils/bmp_format.hpp>
#include <utils/binary_writer.hpp>

const std::string command_merge::name_("merge");

void command_merge::execute(int argc, char** arguments)
{
  if (argc != 3)
    throw std::invalid_argument("Merge has to be called with 3 arguments");
  bmp_format bmpfileA(arguments[0]);
  bmp_format bmpfileB(arguments[1]);
  binary_writer writer(arguments[2]);
  auto widthA = bmpfileA.get_width();
  auto heightA = bmpfileA.get_height();
  rgb** pixelsA = bmpfileA.get_pixels();
  auto widthB = bmpfileB.get_width();
  auto heightB = bmpfileB.get_height();
  rgb** pixelsB = bmpfileB.get_pixels();

  if (heightA != heightB)
    throw std::runtime_error("Unable to mix different height bitmaps!");

  bmpfileA.dump_header(writer.file, bmpfileA.get_width() + bmpfileB.get_width(), bmpfileA.get_height());

  for (std::size_t i = 0; i < heightA; ++i)
  {
    writer.write(pixelsA[i], widthA * sizeof(rgb));
    writer.write(pixelsB[i], widthB * sizeof(rgb));
  }
}
