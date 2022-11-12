#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <vector>
#include "Sudoku.hpp"

class Backtrace
{
public:
  Backtrace(const Sudoku& sudoku) ;
  void print_any_solution() const ;
  void find_any_solution() ;
private:
  void step() ;
  std::vector<Sudoku> solution_candidates ;
  std::vector<Sudoku> solutions ;
};

#endif
