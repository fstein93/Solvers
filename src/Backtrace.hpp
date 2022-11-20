#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <vector>
#include "Sudoku.hpp"

// TODO
// - Extend to other kinds of puzzles

class Backtrace
{
public:
  // Constructors
  Backtrace(const Sudoku& sudoku) noexcept ;
  // Printers to cout
  void print_any_solution() const noexcept ;
  // Call these functions to solve the puzzle until the given constraint can be decided
  void find_any_solution() noexcept ;
  void find_unique_solution() noexcept ;
  void find_all_solutions() noexcept ;
  // Check the results of partial solution
  // Provides only valid results if the algorithm made sufficient progress which is to
  // be checked with the functions below if the given solution step was not already request beforehand
  bool has_a_solution() const noexcept {return !solutions.empty() ;} ;
  bool has_unique_solution() const noexcept {return solutions.size()==1 ;} ;
  // Get the number of solutions
  size_t number_of_solutions() const noexcept {return solutions.size() ;} ;
  // Use these functions to which solution state can be correctly decided
  // These checks are used internally within the find_ routines
  bool is_completely_solved() const noexcept {return solution_candidates.empty() ;} ;
  bool decide_any_solution() const noexcept {return !solutions.empty() || solution_candidates.empty() ;} ;
  bool decide_unique_solution() const noexcept {return solutions.size() > 1 || solution_candidates.empty() ;} ;
private:
  void step() noexcept ;
  std::vector<Sudoku> solution_candidates ;
  std::vector<Sudoku> solutions ;
};

#endif
