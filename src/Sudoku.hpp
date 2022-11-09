#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>
#include "Sudoku_Line.hpp"

class Sudoku
{
public:
  // Constructors
  Sudoku() : board_(81) {} ;
  Sudoku(const size_t board[81]) : board_(board, board+81) {} ;
  // Print Sudoku on cout
  void print() const ;
  // Check validity of the Sudoku
  bool is_valid() const ;
private:
  // Extract row/col/block containing a given element
  Sudoku_Line extract_row(const size_t global) const ;
  Sudoku_Line extract_col(const size_t global) const ;
  Sudoku_Line extract_block(const size_t global) const ;
  // Convert global index to row/col/block numbers
  static size_t constexpr global2row(const size_t global) {return global/9 ;} ;
  static size_t constexpr global2col(const size_t global) {return global%9 ;} ;
  static size_t constexpr global2block(const size_t global) {return global2row(global)/3*3+global2col(global) ;} ;
  // The actual container
  std::vector<size_t> board_ ;
};

#endif
