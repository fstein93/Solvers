#include <stddef.h>
#include <iostream>
#include "utils.hpp"

using namespace std ;

void utils::add_separator(const size_t i, const size_t line_length, ostream &outputstream)
{
  if ((i+1)%line_length)
  {
    outputstream << " " ;
  }
  else
  {
    outputstream << endl ;
  }
}

void utils::add_separator_block(const size_t i, const size_t block_size, ostream &outputstream)
{
  if ((i+1)%block_size)
  {
    outputstream << " " ;
  }
  else
  {
    outputstream << "|" ;
  }
}
