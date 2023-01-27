#ifndef SUDOKU_LINE_HPP
#define SUDOKU_LINE_HPP

#include <stddef.h>
#include <vector>
#include <iostream>

class Sudoku_Line
{
public:
  void print() const noexcept
  {
    for (const size_t& element : line_)
    {
      std::cout << element << " " ;
    }
    std::cout << std::endl ;
  }

  bool test() const noexcept
  {
    // Find the number in the line
    bool found[] = {false, false, false, false, false, false, false, false, false} ;
    for (const size_t& number : line_)
    {
      // Skip if the element is not set (set to zero)
      if (is_valid_number(number))
      {
        // If you have already found it, it is set twice, so the line is invalid
        if (found[number-1]) return false ;
        // If the number was not found before, set its state to found
        found[number-1] = true ;
      }
    }
    return true ;
  }

  void remove_options(bool (&options)[9]) const noexcept
  {
    for (const size_t& number : line_)
    {
      if (is_valid_number(number))
      {
        options[number-1] = false ;
      }
    }
  }
  Sudoku_Line(const std::vector<size_t> line) noexcept : line_(line) {line_.resize(9) ;} ;
  static constexpr bool is_valid_number(const size_t number) noexcept { return (number > 0 && number < 10) ; }
private:
  std::vector<size_t> line_ ;
};

#endif
