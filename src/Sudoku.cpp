#include <stddef.h>
#include <iostream>
#include <sstream>
#include "Sudoku.hpp"
#include "Sudoku_Line.hpp"
#include "utils.hpp"

using namespace std ;

// TODO
// - Add info about how Sudoku was create (from scratch or by adding number at a given field)
// - Accelerate Sudoku::field_with_fewest_options
// - Accelerate Sudoku::number_of_options
// - Refactor print functions (maybe with Lambda functions)
// - Declare a function to determine all fields within the same row, col and block

const string row_block_separator = "+-----+-----+-----+" ;

Sudoku::Sudoku(const Sudoku& sudoku, const size_t field, const size_t element) noexcept : board_(sudoku.board_), grid_(3,3)
{
  board_[field] = element ;
  const size_t row2change = grid_.global2row(field) ;
  const size_t col2change = grid_.global2col(field) ;
  const size_t block2change = grid_.global2block(field) ;
  size_t idx = 0 ;
  for (const vector<size_t> options : sudoku.options_)
  {
    if (grid_.global2row(idx) != row2change && grid_.global2col(idx) != col2change && grid_.global2block(idx) != block2change)
    {
      options_.push_back(options) ;
    }
    else if (idx != field)
    {
      vector<size_t> new_options ;
      for (const size_t& el : options)
      {
        if (el != element) new_options.push_back(el) ;
      }
      options_.push_back(new_options) ;
    }
    else
    {
      options_.push_back(vector<size_t>({element})) ;
    }
++idx ;
  }
}

void Sudoku::setup_options() noexcept
{
  for (size_t global = 0 ; global < 81 ; global++)
  {
    if (Sudoku_Line::is_valid_number(board_[global]))
    {
      options_.push_back(vector<size_t>({board_[global]})) ;
    }
    else
    {
      // Extract local row/col/block and exclude already set numbers
      bool options[9] = {true, true, true, true, true, true, true, true, true} ;
      extract_row(global).remove_options(options) ;
      extract_col(global).remove_options(options) ;
      extract_block(global).remove_options(options) ;
      // Add the new options
      vector<size_t> new_options ;
      for (size_t i = 0 ; i < 9 ; i++)
      {
       if (options[i])
        {
          new_options.push_back(i+1) ;
        }
      }
      options_.push_back(new_options) ;
    }
  }
  options_.resize(81) ;
}

// Print Sudoku row-wise
void Sudoku::print(ostream& stream=cout) const noexcept
{
  stream << row_block_separator << endl ;
  for (size_t i = 0 ; i < 9 ; i++)
  {
    // Use buffer to print whole lines (important if we print to std::err)
    // Otherwise, we will print each junk in a separate line
    stringstream row ;
    row << "|" ;
    for (size_t j = i*9 ; j < (i+1)*9 ; j++)
    {
      row << board_[j] ;
      utils::add_separator_block(j, 3, row) ;
    }
    stream << row.str() << endl ;
    if (i%3==2) stream << row_block_separator << endl ;
  }
}

void Sudoku::print_number_of_options() const noexcept
{
  cout << row_block_separator << endl ;
  for (size_t i = 0 ; i < 9 ; i++)
  {
    // Use buffer to print whole lines (important if we print to std::err)
    // Otherwise, we will print each junk in a separate line
    stringstream row ;
    row << "|" ;
    for (size_t j = i*9 ; j < (i+1)*9 ; j++)
    {
      row << (options_[j]).size() ;
      utils::add_separator_block(j, 3, row) ;
    }
    cout << row.str() << endl ;
    if (i%3==2) cout << row_block_separator << endl ;
  }
}

// Check validity of a Sudoku
// - Check for unvalid numbers
// - Check row/col/block
bool Sudoku::is_valid() const noexcept
{
  for (const size_t& element : board_)
  {
    if (element > 9) { return false ; }
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

bool Sudoku::is_completely_filled() const noexcept
{
  for (const size_t& element : board_)
  {
    if (!Sudoku_Line::is_valid_number(element)) return false ;
  }
  return true ;
}

size_t Sudoku::field_with_fewest_options() const noexcept
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
std::vector<Sudoku> Sudoku::get_next_candidates() const noexcept
{
  vector<Sudoku> list_of_candidates ;
  const size_t next_field = field_with_fewest_options() ;
  for (const size_t& element : list_of_options(next_field))
  {
    list_of_candidates.push_back(Sudoku(board_, next_field, element)) ;
  }
  return list_of_candidates ;
}

// Extraction routines
// First, determine first element of the given set
// Then, compile elements of the given set starting from the first element
Sudoku_Line Sudoku::extract_row(const size_t global) const noexcept
{
  vector<size_t> row ;
  row.reserve(9) ;
  for (const size_t& idx : grid_.elements_in_same_row_as(global)) row.push_back(board_[idx]) ;
  return Sudoku_Line(row) ;
}

Sudoku_Line Sudoku::extract_col(const size_t global) const noexcept
{
  vector<size_t> col ;
  col.reserve(9) ;
  for (const size_t& idx : grid_.elements_in_same_col_as(global)) col.push_back(board_[idx]) ;
  return Sudoku_Line(col) ;
}

Sudoku_Line Sudoku::extract_block(const size_t global) const noexcept
{
  vector<size_t> block ;
  block.reserve(9) ;
  for (const size_t& idx : grid_.elements_in_same_block_as(global)) block.push_back(board_[idx]) ;
  return Sudoku_Line(block) ;
}
