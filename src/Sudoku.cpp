#include <iostream>
#include "Sudoku.hpp"

using namespace std ;

void Sudoku::print() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    cout << board[i] ;
    if (i%9!=8)
    {
      cout << " " ;
    }
    else
    {
      cout << endl ;
    }
  }
}
