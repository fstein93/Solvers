#include "Sudoku_Line.hpp"

bool Sudoku_Line::test_Line() const
{
  // Find the number in the line
  bool found[] = {false, false, false, false, false, false, false, false, false} ;
  for (size_t idx = 0 ; idx < 9 ; idx++)
  {
    const size_t number = line_[idx]-1 ;
    // Skip if the element is not set (set to zero)
    if (number > 0)
    {
      // If you have already found it, it is set twice, so the line is invalid
      if (found[number-1]) return false ;
      // If the number was not found before, set its state to found
      found[number-1] = true ;
    }
  }
  return true ;
}
