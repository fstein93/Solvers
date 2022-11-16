#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <vector>
#include "Sudoku.hpp"

// TODO
// - Refactor criteria of find_*/has_* functions
// - Extend to other kinds of puzzles

class Backtrace
{
public:
  Backtrace(const Sudoku& sudoku) ;
  void print_any_solution() const ;
  void find_any_solution() ;
  void find_unique_solution() ;
  void find_all_solutions() ;
  bool has_a_solution() const {return !solutions.empty() ;} ;
  bool has_unique_solution() const {return solutions.size()==1 ;} ;
  size_t number_of_solutions() const {return solutions.size() ;} ;
  bool is_completely_solved() const {return solution_candidates.empty() ;} ;
private:
  void step() ;
  std::vector<Sudoku> solution_candidates ;
  std::vector<Sudoku> solutions ;
};

#endif
