#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <stddef.h>
#include <vector>
#include <iostream>
#include "Sudoku_Line.hpp"

class Sudoku
{
public:
  // Constructors
  Sudoku() : board_(81) {} ;
  Sudoku(const size_t board[81]) : board_(board, board+81) {} ;
  Sudoku(const std::vector<size_t> board) : board_(board) {board_.resize(81) ;} ;
  // Print Sudoku to a stream
  void print(std::ostream& stream) const ;
  // Print number of options for each field
  void print_number_of_options() const ;
  // Check validity of the Sudoku
  bool is_valid() const ;
  // Find field with the fewest number of options
  size_t field_with_fewest_options() const ;
  // Check whether all fields are set
  bool is_completely_filled() const ;
  // Check whether the solution is correct
  bool is_correctly_solved() const {return (is_completely_filled() && is_valid()) ;} ;
  // Get a list of next possible candidates
  std::vector<Sudoku> get_next_candidates() const ;
  // Determine the new options of a given field
  std::vector<size_t> list_of_options(const size_t global) const ;
  // Apply the new options to a Sudoku
  std::vector<Sudoku> next_step(const size_t global) const ;
private:
  // Extract row/col/block containing a given element
  Sudoku_Line extract_row(const size_t global) const ;
  Sudoku_Line extract_col(const size_t global) const ;
  Sudoku_Line extract_block(const size_t global) const ;
  // Convert global index to row/col/block numbers
  static size_t constexpr global2row(const size_t global) {return global/9 ;} ;
  static size_t constexpr global2col(const size_t global) {return global%9 ;} ;
  static size_t constexpr global2block(const size_t global) {return global2row(global)/3*3+global2col(global)/3 ;} ;
  // Determine the number of options of a given field
  size_t number_of_options(const size_t global) const ;
  // The actual container
  std::vector<size_t> board_ ;
};

#endif
