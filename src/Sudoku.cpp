#include <iostream>
#include "Sudoku.hpp"

using namespace std ;

Sudoku::Sudoku(const size_t board[81]) : board_(board, board+81) 
{
  try
  {
    check_sudoku() ;
  }
  catch (size_t& e)
  {
    cerr << "Found a value larger than 9 : " << e << endl ;
  }
}

void Sudoku::print() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    cout << board_[i] ;
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

void Sudoku::check_sudoku() const
{
  for (size_t i = 0 ; i < 81 ; i++)
  {
    if (board_[i] > 9) throw board_[i] ;
  }
}

