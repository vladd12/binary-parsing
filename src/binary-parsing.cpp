#include "binary-parsing/binary-parsing.hpp"

int binary_parsing::test(int value)
{
  return value * 2;
}

void binary_parsing::parse(const std::string &filepath)
{
  parse(std::filesystem::path(filepath));
}

void binary_parsing::parse(const std::filesystem::path &filepath)
{
  const std::uintmax_t size = std::filesystem::file_size(filepath);
  byte_array buffer(size);
  std::ifstream file(filepath, std::ios_base::binary);
  /// @TODO copy from file to buffer
  parse(buffer);
}

void binary_parsing::parse(std::ifstream &file)
{
  file.seekg(0, std::ios_base::end);
  const std::uintmax_t size = file.tellg();
  file.seekg(0, std::ios_base::beg);
  byte_array buffer(size);
  /// @TODO copy from file to buffer
  parse(buffer);
}

void binary_parsing::parse(byte_array &buffer)
{
  ;
}
