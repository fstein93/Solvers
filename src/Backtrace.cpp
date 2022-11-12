#include <iostream>
#include "Backtrace.hpp"

using namespace std ;

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
    solutions[0].print() ;
  }
}
