#include <stddef.h>
#include <iostream>
#include "utils.hpp"

using namespace std ;

void utils::add_separator(const size_t i, const size_t line_length)
{
  if ((i+1)%line_length)
  {
    cout << " " ;
  }
  else
  {
    cout << endl ;
  }
}
