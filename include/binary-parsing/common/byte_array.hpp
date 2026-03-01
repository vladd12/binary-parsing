#pragma once

#include <array>
#include <binary-parsing/common/types.hpp>
#include <memory>

namespace binary_parsing
{

class byte_array
{
private:
  std::unique_ptr<u8[]> m_bytes;
  std::size_t m_position;

public:
  explicit byte_array(const std::size_t size) : m_bytes(std::make_unique<u8[]>(size)), m_position(0)
  {
  }

  template <std::size_t N> //
  byte_array(const std::array<u8, N> &array) : byte_array(N)
  {
    static_assert(sizeof(u8) == 1); // maybe it could be in types.hpp
    std::memcpy(reinterpret_cast<char *>(m_bytes.get()), reinterpret_cast<char *>(&array[0]), N);
  }
};

}
