#include <iostream>
#include "Sudoku.hpp"
#include "Sudoku_Line.hpp"

using namespace std ;

// Print Sudoku row-wise
void Sudoku::print() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    cout << board_[i] ;
    if (i%9!=8)
    {
      cout << " " ;
    }
    else
    {
      cout << endl ;
    }
  }
}

// Check validity of a Sudoku
// - Check for unvalid numbers
bool Sudoku::is_valid() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    if (board_[i] > 9) return false ;
  }
  return true ;
}

// Extraction routines
// First, determine first element of the given set
// Then, compile elements of the given set starting from the first element
Sudoku_Line Sudoku::extract_row(const size_t global) const
{
  const size_t first_element = global - global2col(global) ;
  return Sudoku_Line({board_[first_element], board_[first_element+1], board_[first_element+2], board_[first_element+3], board_[first_element+4], board_[first_element+5], board_[first_element+6], board_[first_element+7], board_[first_element+8]}) ;
}

Sudoku_Line Sudoku::extract_col(const size_t global) const
{
  const size_t first_element = global - 9*global2row(global) ;
  return Sudoku_Line({board_[first_element], board_[first_element+9], board_[first_element+18], board_[first_element+27], board_[first_element+36], board_[first_element+45], board_[first_element+54], board_[first_element+63], board_[first_element+72]}) ;
}

Sudoku_Line Sudoku::extract_block(const size_t global) const
{
  const size_t first_element = global - (global2row(global)%3)*9 - global2col(global)%3 ;
  return Sudoku_Line({board_[first_element], board_[first_element+1], board_[first_element+2], board_[first_element+9], board_[first_element+10], board_[first_element+11], board_[first_element+18], board_[first_element+19], board_[first_element+20]}) ;
}
