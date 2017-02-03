#include <commands/impl/command_split.hpp>
#include <utils/bmp_format.hpp>
#include <utils/binary_writer.hpp>

const std::string command_split::name_("split");

//To jest totalna patologia. Dziala tylko rozmiar bedacy wielokrotnoscia 4 (bo dziele inta)
//I do tego ten algorytm xD
void command_split::execute(int argc, char** arguments)
{
  if (argc != 1)
    throw std::invalid_argument("Flip has to be called with 1 argument");
  bmp_format bmpfile(arguments[0]);
  binary_writer writers[4] { std::string("1_") + arguments[0],
                             std::string("2_") + arguments[0],
                             std::string("3_") + arguments[0],
                             std::string("4_") + arguments[0]
                           };
  auto width = bmpfile.get_width();
  auto height = bmpfile.get_height();
  rgb** pixels = bmpfile.get_pixels();
  for (int i = 0; i < 4; ++i) bmpfile.dump_header(writers[i].file, width / 2, height / 2);

  for (std::size_t i = 0; i < height / 2; ++i)
  {
    writers[0].write(pixels[i], width * sizeof(rgb) / 2);
    writers[1].write(pixels[i] + width / 2, width * sizeof(rgb) / 2);
    writers[2].write(pixels[i + height / 2], width * sizeof(rgb) / 2);
    writers[3].write(pixels[i + height / 2] + width / 2, width * sizeof(rgb) / 2);

  }

}
