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
  void find_unique_solution() ;
  void find_all_solutions() ;
  bool has_a_solution() const ;
  bool has_unique_solution() const ;
  size_t number_of_solutions() const ;
  bool is_completely_solved() const ;
private:
  void step() ;
  std::vector<Sudoku> solution_candidates ;
  std::vector<Sudoku> solutions ;
};

#endif
