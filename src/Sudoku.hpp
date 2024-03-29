#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <stddef.h>
#include <vector>
#include <iostream>
#include "Sudoku_Line.hpp"
#include "Sudoku_Grid.hpp"

class Sudoku
{
public:
  // Constructors
  Sudoku() noexcept : board_(81) {setup_options() ;} ;
  Sudoku(const size_t board[81]) noexcept : board_(board, board+81) {setup_options();} ;
  Sudoku(const std::vector<size_t> board) noexcept : board_(board) {board_.resize(grid_.total_number_of_elements()) ; setup_options() ;} ;
  Sudoku(const Sudoku& sudoku, const size_t field, const size_t element) noexcept ;
  // Print Sudoku to a stream
  void print(std::ostream& stream) const noexcept ;
  // Print number of options for each field
  void print_number_of_options() const noexcept ;
  // Check validity of the Sudoku
  bool is_valid() const noexcept ;
  // Find field with the fewest number of options
  size_t field_with_fewest_options() const noexcept ;
  // Check whether all fields are set
  bool is_completely_filled() const noexcept ;
  // Check whether the solution is correct
  bool is_correctly_solved() const noexcept {return (is_completely_filled() && is_valid()) ;} ;
  // Get a list of next possible candidates
  std::vector<Sudoku> get_next_candidates() const noexcept ;
  // Determine the new options of a given field
  std::vector<size_t> list_of_options(const size_t global) const noexcept {return options_[global] ; };
  // Apply all obvious simplifications to a Sudoku
  void simplify() noexcept ;
private:
  // Setup options_ vector from the board array
  void setup_options() noexcept ;
  // Extract row/col/block containing a given element
  Sudoku_Line extract_row(const size_t global) const noexcept ;
  Sudoku_Line extract_col(const size_t global) const noexcept ;
  Sudoku_Line extract_block(const size_t global) const noexcept ;
  // Determine the number of options of a given field
  size_t number_of_options(const size_t global) const noexcept {return list_of_options(global).size() ; };
  // The actual container
  std::vector<size_t> board_ ;
  std::vector<std::vector<size_t>> options_ ;
  // Information on the Grid
  const Sudoku_Grid<size_t> grid_ = Sudoku_Grid<size_t>(3, 3) ;
};

#endif
