#ifndef SUDOKU_LINE_HPP
#define SUDOKU_LINE_HPP

#include <stddef.h>

struct Sudoku_Line
{
public:
  bool test_line() const ;
  std::size_t line_[9] ;
};

#endif
