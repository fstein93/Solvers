#ifndef SUDOKU_LINE_HPP
#define SUDOKU_LINE_HPP

#include <stddef.h>
#include <vector>

class Sudoku_Line
{
public:
  Sudoku_Line(const std::vector<size_t> line) : line_(line) {line_.resize(9) ;} ;
  bool test() const ;
  void print() const ;
  void remove_options(bool (&options)[9]) const ;
  static constexpr bool is_valid_number(const size_t number) { return (number > 0 && number < 10) ; }
private:
  std::vector<size_t> line_ ;
};

#endif
