#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <vector>
#include "Sudoku.hpp"

class Backtrace
{
public:
  Backtrace(Sudoku sudoku) : initial_sudoku(sudoku) {} ;
  void print_any_solution() const ;
private:
  const Sudoku initial_sudoku;
  std::vector<Sudoku> solution_candidates ;
  std::vector<Sudoku> solutions ;
};

#endif
