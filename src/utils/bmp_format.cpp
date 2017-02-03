#include <utils/bmp_format.hpp>
#include <utils/binary_reader.hpp>

bmp_format::bmp_format(const std::string& filename)
  : filename(filename)
{
  binary_reader reader(filename);
  std::string contents(reader.get_actual_file_contents());
  if (contents.size() < bmp_header_size_)
    throw std::runtime_error("File is malformed, missing header");
  memcpy(&header[0], &contents[0], header.size());
  if (header[0] != 0x42 || header[1] != 0x4D)
    throw std::runtime_error("File is malformed, magic number is wrong");
  std::size_t filesize = *(std::size_t*)&header[2];
  if (filesize != contents.size())
    throw std::runtime_error("Size from header does not match actual file size");
  width = *(std::size_t*)&header[0x12];
  height = *(std::size_t*)&header[0x16];
  pixels = new rgb*[height];
  for (std::size_t i = 0; i < height; ++i)
  {
    pixels[i] = new rgb[width];
    memcpy(pixels[i], &contents[bmp_header_size_ + i * width * sizeof(rgb)], width * sizeof(rgb));
  }
}

bmp_format::~bmp_format()
{
  if (pixels == nullptr) return;
  for (std::size_t i = 0; i < height; ++i)
    delete[] pixels[i];
  delete[] pixels;
}

bmp_format::bmp_format(const bmp_format& rhs)
  : filename(rhs.filename),
    width(rhs.width),
    height(rhs.height)
{
  pixels = new rgb*[height];
  for (std::size_t i = 0; i < height; ++i)
  {
    pixels[i] = new rgb[width];
    memcpy(pixels[i], rhs.pixels[i], width * sizeof(rgb));
  }
}

bmp_format::bmp_format(bmp_format&& rhs)
  : filename(std::move(rhs.filename)),
    pixels(rhs.pixels),
    width(rhs.width),
    height(rhs.height)
{
  pixels = nullptr;
}

void bmp_format::dump_header(std::ostream& o) const
{
  o.write(&header[0], bmp_header_size_);
}

void bmp_format::dump_header(std::ostream& o, std::size_t new_width, std::size_t new_height) const
{
  o.write(&header[0], 0x12);
  o.write((char*)&new_width, sizeof(std::size_t));
  o.write((char*)&new_height, sizeof(std::size_t));
  o.write(&header[0x1A], 0x1C);
}
