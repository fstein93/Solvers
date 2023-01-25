#include "Square_Grid.hpp"
#include "Square_Grid_test.hpp"
#include <iostream>

using namespace std ;

void test_Square_Grid()
{
  constexpr size_t grid_size = 9 ;
  Square_Grid<> Grid1(grid_size) ;
  size_t index = 0 ;
  for (size_t row = 0 ; row < grid_size ; row++)
  {
    for (size_t col = 0 ; col < grid_size ; col++)
    {
      const size_t global_index = Grid1.local2global(row, col) ;
      if (global_index != index) cerr << "Incorrect global index of field " << index << endl ;
      if (Grid1.global2row(global_index) != row) cerr << "Incorrect row index of field " << index << endl ;
      if (Grid1.global2col(global_index) != col) cerr << "Incorrect col index of field " << index << endl ;
      ++index ;
    }
  }
}
