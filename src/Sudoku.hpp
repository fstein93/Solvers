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
  Sudoku() : board_(81), grid(3,3) {setup_options() ;} ;
  Sudoku(const size_t board[81]) : board_(board, board+81), grid(3,3) {setup_options();} ;
  Sudoku(const std::vector<size_t> board) : board_(board), grid(3,3) {board_.resize(grid.total_number_of_elements()) ; setup_options() ;} ;
  Sudoku(const Sudoku& sudoku, const size_t field, const size_t element) ;
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
  std::vector<size_t> list_of_options(const size_t global) const {return options_[global] ; };
private:
  void setup_options() ;
  std::vector<size_t> list_of_options_low(const size_t global) const ;
  // Extract row/col/block containing a given element
  Sudoku_Line extract_row(const size_t global) const ;
  Sudoku_Line extract_col(const size_t global) const ;
  Sudoku_Line extract_block(const size_t global) const ;
  // Convert global index to row/col/block numbers
  size_t global2rowblock(const size_t global) const {return grid.global2row(global)/3 ;} ;
  size_t global2colblock(const size_t global) const {return grid.global2col(global)/3 ;} ;
  size_t global2block(const size_t global) const {return 3*global2rowblock(global)+global2colblock(global) ;} ;
  // Get indices of all elements in the same row/col/block
  static std::vector<size_t> indices_of_same_row(const size_t global) ;
  static std::vector<size_t> indices_of_same_col(const size_t global) ;
  static std::vector<size_t> indices_of_same_block(const size_t global) ;
  // Determine the number of options of a given field
  size_t number_of_options(const size_t global) const {return list_of_options(global).size() ; };
  // The actual container
  std::vector<size_t> board_ ;
  std::vector<std::vector<size_t>> options_ ;
  // Information on the Grid
  const Sudoku_Grid grid ;
};

#endif
