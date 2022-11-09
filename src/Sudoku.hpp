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
  static int constexpr global2row(const int global) {return global/9 ;} ;
  static int constexpr global2col(const int global) {return global%9 ;} ;
  static int constexpr global2block(const int global) {return global2row(global)/3*3+global2col(global) ;} ;
  std::vector<size_t> board_ ;
};

#endif
