#pragma once

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

} // namespace binary_parsing
