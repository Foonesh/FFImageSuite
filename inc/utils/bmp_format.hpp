#pragma once

#include <string>
#include <iostream>
#include <array>

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
	std::array<char, 0x36> header;

  public:

    bmp_format(const std::string& filename);
	~bmp_format();
    bmp_format(const bmp_format& rhs);
    bmp_format(bmp_format&& rhs);
    bmp_format& operator=(const bmp_format&) = delete;
    bmp_format& operator=(bmp_format&&) = delete;

	const std::string& get_filename() const { return filename; };
	std::size_t get_width() const { return width; };
	std::size_t get_height() const { return height; };
	rgb** get_pixels() const { return pixels; };
	void dump_header(std::ostream& o) const;
	void dump_header(std::ostream& o, std::size_t new_width, std::size_t new_height) const; // to troche smierdzi. 
	//Chce wypisac bitmape ze zmniejszonymi/zwiekszonymi wymiarami, ale width i height sa uzywane przez tablice pixeli

    static const std::size_t bmp_header_size_ = 0x36;

};