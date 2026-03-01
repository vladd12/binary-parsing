#pragma once

#include <binary-parsing/common/byte_array.hpp>
#include <binary-parsing/export.hpp>
#include <filesystem>
#include <fstream>

namespace binary_parsing
{
BINPARS_API int test(int value);

/// PUBLIC API
BINPARS_API void parse(const std::string &filepath);
BINPARS_API void parse(const std::filesystem::path &filepath);

/// INTERNAL API
BINPARS_API void parse(std::ifstream &file);
BINPARS_API void parse(byte_array &buffer);

} // namespace binary_parsing
