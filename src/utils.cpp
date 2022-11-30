#include <stddef.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"

using namespace std ;

void utils::add_separator(const size_t i, const size_t line_length, ostream &outputstream) noexcept
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

void utils::add_separator_block(const size_t i, const size_t block_size, ostream &outputstream) noexcept
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

void utils::remove_element(vector<size_t>& my_vector, const size_t element) noexcept
{
  my_vector.erase(remove(my_vector.begin(), my_vector.end(), element), my_vector.end()) ;
}
