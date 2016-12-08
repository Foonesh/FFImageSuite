#include <commands/impl/command_man.hpp>
#include <commands/command_factory.hpp>

#include <iostream>

const std::string command_man::name_("man");

void command_help::execute()
{
  std::cout << "NAME";
  std::cout << "FFImageSuite";
  std::cout << "SYNOPSIS";
  std::cout << "ff [-divide number] [-reverse] [-rotate amount] path_to_img1/img1.ext1 path_to_img2/img2.ext2";
  std::cout << "DESCRIPTION";
  std::cout << "FFImageSuite enables you to change image formats freely between the following: .jpg, .png, .bmp. File location must be supplied by the user, as well as an information where the file should be saved. It is possible to perform additional operations on the image whilst converting the format.";
  std::cout << "OPTIONS";
  std::cout << "-divide number    also divide the processed image to [number] smaller images. [number] must be a multiple of 4.";
  std::cout << "-reverse          reverse the colours in the resulting image(s)";
  std::cout << "-rotate amount    rotate the resulting image(s) by [amount] degrees. [amount] must be either 90, 180 or 270.";
  std::cout << "FILES";
  std::cout << "(TODO)Location of config files etc.";
  std::cout << "KNOWN BUGS";
  std::cout << "None yet";
  std::cout << "AUTHORS";
  std::cout << "Daniel Koperniak, Marcin Owcarz, Krzysztof Pszczola";
  std::cout << "LAST CHANGE: 08.12.2016";
}
