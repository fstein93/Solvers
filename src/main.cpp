#include <iostream>
#include "Sudoku.hpp"
#include "utils.hpp"
#include "Backtrace.hpp"

using namespace std ;

void write_sudoku(Sudoku& sudoku)
{
  sudoku.print(cout) ;
  cout << "Valid: " << sudoku.is_valid()  << endl ;
  cout << "Completely filled: " << sudoku.is_completely_filled()  << endl ;
  cout << "Correctly solved: " << sudoku.is_correctly_solved()  << endl ;

  cout << "Number of options" << endl ;
  sudoku.print_number_of_options() ;
  cout << endl ;

  cout << endl ;
}

int main()
{
  Sudoku sudoku1 ;
  write_sudoku(sudoku1) ;

  constexpr size_t input_solved[] = {5, 3, 4, 6, 7, 8, 9, 1, 2,
                  6, 7, 2, 1, 9, 5, 3, 4, 8,
                  1, 9, 8, 3, 4, 2, 5, 6, 7,
                  8, 5, 9, 7, 6, 1, 4, 2, 3,
                  4, 2, 6, 8, 5, 3, 7, 9, 1,
                  7, 1, 3, 9, 2, 4, 8, 5, 6,
                  9, 6, 1, 5, 3, 7, 2, 8, 4,
                  2, 8, 7, 4, 1, 9, 6, 3, 5,
                  3, 4, 5, 2, 8, 6, 1, 7, 9} ;
  Sudoku sudoku2(input_solved) ;
  write_sudoku(sudoku2) ;

  constexpr size_t input_error[] = {5, 3, 4, 6, 7, 8, 9, 1, 2,
                  6, 7, 2, 1, 9, 5, 3, 4, 8,
                  1, 9, 8, 3, 4, 2, 5, 6, 7,
                  8, 5, 9, 7, 6, 1, 4, 2, 3,
                  4, 2, 6, 8, 5, 3, 7, 9, 1,
                  7, 1, 3, 9, 2, 4, 8, 5, 6,
                  9, 6, 1, 5, 3, 7, 2, 8, 4,
                  2, 8, 7, 4, 1, 9, 6, 3, 5,
                  3, 4, 5, 2, 8, 6, 1, 7, 2} ;
  Sudoku sudoku3(input_error) ;
  write_sudoku(sudoku3) ;

  constexpr size_t input_unsolved[] = {0, 3, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 1, 9, 5, 0, 0, 0,
                  0, 0, 8, 0, 0, 0, 0, 6, 0,
                  8, 0, 0, 0, 6, 0, 0, 0, 0,
                  4, 0, 0, 8, 0, 0, 0, 0, 1,
                  0, 0, 0, 0, 2, 0, 0, 0, 0,
                  0, 6, 0, 0, 0, 0, 2, 8, 0,
                  0, 0, 0, 4, 1, 9, 0, 0, 5,
                  0, 0, 0, 0, 0, 0, 0, 7, 0} ;
  Sudoku sudoku4(input_unsolved) ;
  write_sudoku(sudoku4) ;
  Backtrace backtrace(sudoku4) ;
  backtrace.print_any_solution() ;

  return 0 ;
}
