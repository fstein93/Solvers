#ifndef SUDOKU_LINE_HPP
#define SUDOKU_LINE_HPP

#include <stddef.h>

struct Sudoku_Line
{
public:
  bool test() const ;
  void print() const ;
  void remove_options(bool (&options)[9]) const ;
  static constexpr bool is_valid_number(const size_t number) { return (number > 0 && number < 10) ; }
  size_t line_[9] ;
};

#endif
