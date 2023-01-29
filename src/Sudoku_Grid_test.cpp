#include "Sudoku_Grid.hpp"
#include "Sudoku_Grid_test.hpp"
#include <iostream>

using namespace std ;

template <typename T>
void test_Sudoku_Grid_low(const T row_block_size, const T col_block_size)
{
  Sudoku_Grid<T> Grid1(row_block_size, col_block_size) ;
  const T col_size = row_block_size*col_block_size ;
  const T grid_size = col_size*col_size ;
  T index = 0 ;
  for (T row_block = 0 ; row_block < col_block_size ; row_block++)
  {
    for (T local_row = 0 ; local_row < row_block_size ; local_row++)
    {
      const T row = row_block_size*row_block+local_row ;
      for (T col_block = 0 ; col_block < row_block_size ; col_block++)
      {
        for (T local_col = 0 ; local_col < col_block_size ; local_col++)
        {
          const T col = col_block_size*col_block+local_col ;

          const T global_index = Grid1.local2global(row, col) ;
          if (global_index != index) cerr << "Incorrect global index of field " << index << endl ;
          if (Grid1.global2row(global_index) != row) cerr << "Incorrect row index of field " << index << endl ;
          if (Grid1.global2col(global_index) != col) cerr << "Incorrect col index of field " << index << endl ;
          if (Grid1.global2rowblock(global_index) != row_block) cerr << "Incorrect row block index of field " << index << endl ;
          if (Grid1.global2colblock(global_index) != col_block) cerr << "Incorrect col block index of field " << index << endl ;
          if (Grid1.global2block(global_index) != row_block_size*row_block+col_block) cerr << "Incorrect block index of field " << index << endl ;

          vector<T> elements = Grid1.elements_in_same_row_as(global_index) ;
          if (((T) elements.size()) != col_size) cerr << "Incorrect number of elements in the same row as " << global_index << endl ;
          for (const T& element : elements)
          {
            if (Grid1.global2row(element) != row) cerr << "Element of a different row found in elements_in_same_row_as of element " << index << " : " << element << endl ;
          }

          elements = Grid1.elements_in_same_col_as(global_index) ;
          if (((T) elements.size()) != col_size) cerr << "Incorrect number of elements in the same col as " << global_index << endl ;
          for (const T& element : elements)
          {
            if (Grid1.global2col(element) != col) cerr << "Element of a different col found in elements_in_same_col_as of element " << index << " : " << element << endl ;
          }

          elements = Grid1.elements_in_same_row_or_col_as(global_index) ;
          if (((T) elements.size()) != ((T) 2)*col_size-((T) 1)) cerr << "Incorrect number of elements in the same row or col as " << global_index << endl ;
          for (const T& element : elements)
          {
            if (Grid1.global2row(element) != row && Grid1.global2col(element) != col) cerr << "Element of a different row and col found in elements_in_same_row_or_col_as of element " << index << " : " << element << endl ;
          }

          ++index ;
        }
      }
    }
  }
  if (Grid1.get_number_of_cols() != col_size) cerr << "Incorrect number of cols" << endl ;
  if (Grid1.total_number_of_elements() != grid_size) cerr << "Incorrect number of fields" << endl ;
}

void test_Sudoku_Grid()
{
  test_Sudoku_Grid_low<size_t>(0, 0) ; 
  test_Sudoku_Grid_low<size_t>(1, 1) ; 
  test_Sudoku_Grid_low<size_t>(3, 3) ; 
  test_Sudoku_Grid_low<size_t>(7, 4) ; 
  test_Sudoku_Grid_low<size_t>(2, 4) ; 
  test_Sudoku_Grid_low<size_t>(4, 2) ;

  test_Sudoku_Grid_low<int>(0, 0) ;
  test_Sudoku_Grid_low<int>(1, 1) ;
  test_Sudoku_Grid_low<int>(3, 3) ;
  test_Sudoku_Grid_low<int>(7, 4) ;
  test_Sudoku_Grid_low<int>(2, 4) ;
  test_Sudoku_Grid_low<int>(4, 2) ;

  test_Sudoku_Grid_low<long int>(0, 0) ;
  test_Sudoku_Grid_low<long int>(1, 1) ;
  test_Sudoku_Grid_low<long int>(3, 3) ;
  test_Sudoku_Grid_low<long int>(7, 4) ;
  test_Sudoku_Grid_low<long int>(2, 4) ;
  test_Sudoku_Grid_low<long int>(4, 2) ;
 
}
