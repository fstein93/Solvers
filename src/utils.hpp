#ifndef UTILS_HPP
#define UTILS_HPP

#include <stddef.h>
#include <iostream>

namespace utils
{
  void add_separator(const size_t i, const size_t line_length, std::ostream &outputstream) ;
  void add_separator_block(const size_t i, const size_t block_size, std::ostream &outputstream) ;
}

#endif
