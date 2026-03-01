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
  /// @TODO
}
