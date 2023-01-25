#include "Square_Grid.hpp"
#include "Square_Grid_test.hpp"
#include <iostream>

using namespace std ;

template <typename T>
void test_Square_Grid_conversion(const T grid_size)
{
  Square_Grid<T> Grid1(grid_size) ;
  T index = 0 ;
  for (T row = 0 ; row < grid_size ; row++)
  {
    for (T col = 0 ; col < grid_size ; col++)
    {
      const T global_index = Grid1.local2global(row, col) ;
      if (global_index != index) cerr << "Incorrect global index of field " << index << endl ;
      if (Grid1.global2row(global_index) != row) cerr << "Incorrect row index of field " << index << endl ;
      if (Grid1.global2col(global_index) != col) cerr << "Incorrect col index of field " << index << endl ;
      ++index ;
    }
  }
}

void test_Square_Grid()
{
  test_Square_Grid_conversion<size_t>(0) ; 
  test_Square_Grid_conversion<size_t>(1) ; 
  test_Square_Grid_conversion<size_t>(3) ; 
  test_Square_Grid_conversion<size_t>(7) ; 
  test_Square_Grid_conversion<size_t>(8) ; 
  test_Square_Grid_conversion<size_t>(9) ;
 
  test_Square_Grid_conversion<int>(0) ;
  test_Square_Grid_conversion<int>(1) ;
  test_Square_Grid_conversion<int>(3) ;
  test_Square_Grid_conversion<int>(7) ;
  test_Square_Grid_conversion<int>(8) ;
  test_Square_Grid_conversion<int>(9) ;

  test_Square_Grid_conversion<long int>(0) ;
  test_Square_Grid_conversion<long int>(1) ;
  test_Square_Grid_conversion<long int>(3) ;
  test_Square_Grid_conversion<long int>(7) ;
  test_Square_Grid_conversion<long int>(8) ;
  test_Square_Grid_conversion<long int>(9) ;
 
}
