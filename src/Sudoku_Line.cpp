#include <stddef.h>
#include <iostream>
#include "Sudoku_Line.hpp"

using namespace std ;

void Sudoku_Line::print() const noexcept
{
  for (const size_t& element : line_)
  {
    cout << element << " " ;
  }
  cout << endl ;
}

bool Sudoku_Line::test() const noexcept
{
  // Find the number in the line
  bool found[] = {false, false, false, false, false, false, false, false, false} ;
  for (const size_t& number : line_)
  {
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

void Sudoku_Line::remove_options(bool (&options)[9]) const noexcept
{
  for (const size_t& number : line_)
  {
    if (is_valid_number(number))
    {
      options[number-1] = false ;
    }
  }
}
