#include <stddef.h>
#include "Sudoku_Line.hpp"

using namespace std ;

bool Sudoku_Line::test_line() const
{
  // Find the number in the line
  bool found[] = {false, false, false, false, false, false, false, false, false} ;
  for (size_t idx = 0 ; idx < 9 ; idx++)
  {
    const size_t number = line_[idx]-1 ;
    // Skip if the element is not set (set to zero)
    if (is_valid_number(number))
    {
      // If you have already found it, it is set twice, so the line is invalid
      if (found[number-1]) return false ;
      // If the number was not found before, set its state to found
      found[number-1] = true ;
    }
  }
  return true ;
}

void Sudoku_Line::remove_options(bool (&options)[9]) const
{
  for (size_t i = 0 ; i < 9 ; i++)
  {
    const size_t number = line_[i] ;
    if (is_valid_number(number))
    {
      options[number-1] = true ;
    }
  }
}
