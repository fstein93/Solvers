#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>
#include "Sudoku_Line.hpp"

class Sudoku
{
public:
  Sudoku() : board_(81) {} ;
  Sudoku(const size_t board[81]) ;
  void print() const ;
private:
  void check_sudoku() const ;
  Sudoku_Line extract_row(const size_t global) const ;
  Sudoku_Line extract_col(const size_t global) const ;
  Sudoku_Line extract_block(const size_t global) const ;
  static size_t constexpr global2row(const size_t global) {return global/9 ;} ;
  static size_t constexpr global2col(const size_t global) {return global%9 ;} ;
  static size_t constexpr global2block(const size_t global) {return global2row(global)/3*3+global2col(global) ;} ;
  std::vector<size_t> board_ ;
};

#endif
