#include <iostream>
#include "Backtrace.hpp"

using namespace std ;

Backtrace::Backtrace(const Sudoku& sudoku)
{
  if (sudoku.is_valid())
  {
    if (sudoku.is_correctly_solved())
    {
      solutions.push_back(sudoku) ;
    }
    else
    {
      solution_candidates.push_back(sudoku) ;
    }
  }
}

void Backtrace::print_any_solution() const
{
  if (solutions.empty())
  {
    if (solution_candidates.empty())
    {
      cout << "The given Sudoku has no solutions!" << endl ;
    }
    else
    {
      cout << "In order to print a solution, you have to solve the Sudoku first!" << endl ;
    }
  }
  else
  {
    cout << "There is at least one solution. One of them is" << endl ;
    solutions[0].print(cout) ;
  }
}

void Backtrace::find_any_solution()
{
  while (solutions.empty() && !solution_candidates.empty())
  {
    step() ;
  }
}

void Backtrace::find_unique_solution()
{
  while (solutions.size() < 2 && !solution_candidates.empty())
  {
    step() ;
  }
}

void Backtrace::find_all_solutions()
{
  while (!solution_candidates.empty())
  {
    step() ;
  }
}

void Backtrace::step()
{
  const Sudoku candidate(solution_candidates.back()) ;
  solution_candidates.pop_back() ;
  for (const Sudoku& next_candidate : candidate.get_next_candidates())
  {
    if (next_candidate.is_correctly_solved())
    {
      solutions.push_back(next_candidate) ;
    }
    else
    {
      solution_candidates.push_back(next_candidate) ;
    }
  }
}

bool Backtrace::has_a_solution() const
{
  return !solutions.empty() ;
}

bool Backtrace::has_unique_solution() const
{
  return solutions.size()==1 ;
}

size_t Backtrace::number_of_solutions() const
{
  return solutions.size() ;
}

bool Backtrace::is_completely_solved() const
{
  return solution_candidates.empty() ;
}
