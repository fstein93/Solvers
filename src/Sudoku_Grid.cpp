#include <vector>
#include "Sudoku_Grid.hpp"

using namespace std ;

vector<size_t> Sudoku_Grid::elements_in_same_block_as(const size_t global) const noexcept
{
  const size_t first_element = first_element_in_block_of(global) ;
  vector<size_t> indices ;
  indices.reserve(number_of_cols_) ;
  for (size_t idx_first_col = first_element ; idx_first_col < first_element+number_of_rows_per_block_*number_of_cols_ ; idx_first_col += number_of_cols_)
  {
    for (size_t idx = idx_first_col ; idx < idx_first_col+number_of_cols_per_block_ ; idx++) indices.push_back(idx) ;
  }
  return indices ;
}

vector<size_t> left_over_indices(const size_t index, const size_t max_idx)
{
  vector<size_t> indices ;
  for (size_t idx = 0 ; idx < index ; idx++) indices.push_back(idx) ;
  for (size_t idx = index + 1 ; idx < max_idx ; idx++) indices.push_back(idx) ;
  return indices ;
}

vector<size_t> Sudoku_Grid::elements_in_same_row_or_col_or_blk_as(const size_t global) const noexcept
{
  vector<size_t> indices(Square_Grid<size_t>::elements_in_same_row_or_col_as(global)) ;
  const size_t first_element = first_element_in_block_of(global) ;
  for (const size_t& row : left_over_indices(global2row(global)%3, number_of_rows_per_block_))
  {
    for (const size_t& col : left_over_indices(global2col(global)%3, number_of_cols_per_block_))
    {
      indices.push_back(first_element + row*number_of_cols_ + col) ;
    }
  }
  return indices ;
}
