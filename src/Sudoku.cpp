#include <stddef.h>
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
// - Check row/col/block
bool Sudoku::is_valid() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    if (board_[i] > 9) { return false ; }
  }
  // Check rows
  for (size_t i = 0 ; i < 81 ; i+=9)
  {
    if (!extract_row(i).test()) return false ;
  }
  // Check cols
  for (size_t i = 0 ; i < 9 ; i++)
  {
    if (!extract_col(i).test()) return false ;
  }
  // Check blocks
  for (size_t row = 0 ; row < 9 ; row+=3)
  {
    for (size_t col = 0 ; col < 9 ; col+=3)
    {
      if (!extract_block(9*row+col).test()) return false ;
    }
  }
  return true ;
}

bool Sudoku::is_completely_filled() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    if (!Sudoku_Line::is_valid_number(board_[i])) return false ;
  }
  return true ;
}

size_t Sudoku::field_with_fewest_options() const
{
  size_t field = 0 ;
  size_t min_number_of_options = 9 ;
  for (size_t i = 0 ; i < 81 ; i++)
  {
    const size_t number = board_[i] ;
    if (!Sudoku_Line::is_valid_number(number))
    {
      const size_t num_options = number_of_options(i) ;
      if (num_options <= min_number_of_options)
      {
        field = i ;
        min_number_of_options = num_options ;
      }
    }
  }
  return field ;
}

// Get a list of next possible candidates
std::vector<Sudoku> Sudoku::get_next_candidates() const
{
  vector<Sudoku> list_of_candidates ;
  const size_t next_field = field_with_fewest_options() ;
  const vector<size_t> new_options = list_of_options(next_field) ;
  Sudoku next_sudoku(board_) ;
  size_t& element2adopt = next_sudoku.board_[next_field] ;
  for (const size_t& element : new_options)
  {
    element2adopt = element ;
    list_of_candidates.push_back(next_sudoku) ;
  }
  return list_of_candidates ;
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

// Determine the number of options of a given field
size_t Sudoku::number_of_options(const size_t global) const
{
  // Field is already set, so there is just this single option
  if (board_[global] > 0 || board_[global] <= 9) return 1 ;
  // Extract local row/col/block and exclude already set numbers
  bool options[9] = {} ;
  extract_row(global).remove_options(options) ;
  extract_col(global).remove_options(options) ;
  extract_block(global).remove_options(options) ;
  // Count the options (number of false in options)
  size_t counter = 0 ;
  for (size_t i = 0 ; i < 9 ; i++)
  {
    if (!options[i]) counter++ ;
  }
  return counter ;
}

// Determine the new options of a given field
vector<size_t> Sudoku::list_of_options(const size_t global) const
{
  vector<size_t> new_options ;
  // Field is already set, so there is just this single option
  if (board_[global] > 0 && board_[global] <= 9) return new_options ;
  // Extract local row/col/block and exclude already set numbers
  bool options[9] = {} ;
  extract_row(global).remove_options(options) ;
  extract_col(global).remove_options(options) ;
  extract_block(global).remove_options(options) ;
  // Add the new options
  for (size_t i = 0 ; i < 9 ; i++)
  {
    if (!options[i]) new_options.push_back(i+1) ;
  }
  return new_options ;
}
