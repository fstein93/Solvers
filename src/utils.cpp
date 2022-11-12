#include <stddef.h>
#include <iostream>
#include "utils.hpp"

void utils::add_separator(const size_t i, const size_t line_length)
{
  if ((i+1)%line_length)
  {
    std::cout << " " ;
  }
  else
  {
    std::cout << std::endl ;
  }
}
