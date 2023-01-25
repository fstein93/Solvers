#include "Square_Grid.hpp"
#include "Square_Grid_test.hpp"
#include <iostream>

using namespace std ;

template <typename T>
void test_Square_Grid_low(const T grid_size)
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

      vector<T> elements = Grid1.elements_in_same_row_as(global_index) ;
      if (((T) elements.size()) != grid_size) cerr << "Incorrect number of elements in the same row as " << global_index << endl ;
      for (const T& element : elements)
      {
        if (Grid1.global2row(element) != row) cerr << "Element of a different row found in elements_in_same_row_as of element " << index << " : " << element << endl ;
      }

      elements = Grid1.elements_in_same_col_as(global_index) ;
      if (((T) elements.size()) != grid_size) cerr << "Incorrect number of elements in the same col as " << global_index << endl ;
      for (const T& element : elements)
      {
        if (Grid1.global2col(element) != col) cerr << "Element of a different col found in elements_in_same_col_as of element " << index << " : " << element << endl ;
      }

      elements = Grid1.elements_in_same_row_or_col_as(global_index) ;
      if (((T) elements.size()) != ((T) 2)*grid_size-((T) 1)) cerr << "Incorrect number of elements in the same row or col as " << global_index << endl ;
      for (const T& element : elements)
      {
        if (Grid1.global2row(element) != row && Grid1.global2col(element) != col) cerr << "Element of a different row and col found in elements_in_same_row_or_col_as of element " << index << " : " << element << endl ;
      }

      ++index ;
    }
  }
  if (Grid1.get_number_of_cols() != grid_size) cerr << "Incorrect number of cols" << endl ;
  if (Grid1.total_number_of_elements() != grid_size*grid_size) cerr << "Incorrect number of fields" << endl ;
}

void test_Square_Grid()
{
  test_Square_Grid_low<size_t>(0) ; 
  test_Square_Grid_low<size_t>(1) ; 
  test_Square_Grid_low<size_t>(3) ; 
  test_Square_Grid_low<size_t>(7) ; 
  test_Square_Grid_low<size_t>(8) ; 
  test_Square_Grid_low<size_t>(9) ;
 
  test_Square_Grid_low<int>(0) ;
  test_Square_Grid_low<int>(1) ;
  test_Square_Grid_low<int>(3) ;
  test_Square_Grid_low<int>(7) ;
  test_Square_Grid_low<int>(8) ;
  test_Square_Grid_low<int>(9) ;

  test_Square_Grid_low<long int>(0) ;
  test_Square_Grid_low<long int>(1) ;
  test_Square_Grid_low<long int>(3) ;
  test_Square_Grid_low<long int>(7) ;
  test_Square_Grid_low<long int>(8) ;
  test_Square_Grid_low<long int>(9) ;
 
}
