#pragma once

#include <string>
#include <fstream>

class binary_writer
{

  public:

    binary_writer(const std::string& filepath);

    void write(void* data, std::size_t size);

	std::ofstream file; //qq
};