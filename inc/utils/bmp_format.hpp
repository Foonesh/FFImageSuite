#pragma once

#include <string>

struct rgb
{
  char r, g, b;
};

class bmp_format
{
	const std::string filename;
	std::size_t width;
	std::size_t height;
    rgb** pixels;

  public:

    bmp_format(const std::string& filename);
	~bmp_format();
    bmp_format(const bmp_format& rhs);
    bmp_format(bmp_format&& rhs);
    bmp_format& operator=(const bmp_format&) = delete;
    bmp_format& operator=(bmp_format&&) = delete;

	const std::string& get_filename() { return filename; };
	std::size_t get_width() { return width; };
	std::size_t get_height() { return height; };
	rgb** get_pixels() { return pixels; };

    static const std::size_t bmp_header_size_ = 0x36;

};