#ifndef SUDOKU_LINE_HPP
#define SUDOKU_LINE_HPP

#include <stddef.h>

struct Sudoku_Line
{
public:
  bool test_line() const ;
  void remove_options(bool (&options)[9]) const ;
  size_t line_[9] ;
};

#endif
