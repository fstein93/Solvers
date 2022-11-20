#ifndef SUDOKU_LINE_HPP
#define SUDOKU_LINE_HPP

#include <stddef.h>
#include <vector>

class Sudoku_Line
{
public:
  Sudoku_Line(const std::vector<size_t> line) noexcept : line_(line) {line_.resize(9) ;} ;
  bool test() const noexcept ;
  void print() const noexcept ;
  void remove_options(bool (&options)[9]) const noexcept ;
  static constexpr bool is_valid_number(const size_t number) noexcept { return (number > 0 && number < 10) ; }
private:
  std::vector<size_t> line_ ;
};

#endif
