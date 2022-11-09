#include <iostream>
#include "Sudoku.hpp"

using namespace std ;

int main()
{
  Sudoku sudoku1 ;
  sudoku1.print() ;
  cout << sudoku1.is_valid() << endl ;

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
  sudoku2.print() ;
  cout << sudoku2.is_valid() << endl ;

  constexpr size_t input_error[] = {5, 3, 4, 6, 7, 8, 9, 1, 2,
                  6, 7, 2, 1, 9, 5, 3, 4, 8,
                  1, 9, 8, 3, 4, 2, 5, 6, 7,
                  8, 5, 9, 7, 6, 1, 4, 2, 3,
                  4, 2, 6, 8, 5, 3, 7, 9, 1,
                  7, 1, 3, 9, 2, 4, 8, 5, 6,
                  9, 6, 1, 5, 3, 7, 2, 8, 4,
                  2, 8, 7, 4, 1, 9, 6, 3, 5,
                  3, 4, 5, 2, 8, 6, 1, 7, 10} ;
  Sudoku sudoku3(input_error) ;
  sudoku3.print() ;
  cout << sudoku3.is_valid() << endl ;

  return 0 ;
}
