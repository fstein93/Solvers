#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <vector>
#include "Sudoku.hpp"

class Backtrace
{
public:
  Backtrace(Sudoku sudoku) : initial_sudoku(sudoku) { solution_candidates.push_back(sudoku) ; } ;
private:
  const Sudoku initial_sudoku;
  std::vector<Sudoku> solution_candidates ;
};

#endif
