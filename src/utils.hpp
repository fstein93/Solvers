#ifndef UTILS_HPP
#define UTILS_HPP

#include <stddef.h>
#include <iostream>
#include <vector>

namespace utils
{
  void add_separator(const size_t i, const size_t line_length, std::ostream &outputstream) noexcept ;
  void add_separator_block(const size_t i, const size_t block_size, std::ostream &outputstream) noexcept ;
  void remove_element(std::vector<size_t>& my_vector, const size_t element) noexcept ;
}

#endif
