#include <stddef.h>
#include <iostream>
#include <vector>
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

vector<size_t> utils::remove_element(const vector<size_t>& old_vector, const size_t element) noexcept
{
  vector<size_t> new_vector ;
  for (const size_t& el : old_vector)
  {
    if (el != element) new_vector.push_back(el) ;
  }
  return new_vector ;
}
