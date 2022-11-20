#include <vector>
#include "Sudoku_Grid.hpp"

using namespace std ;

vector<size_t> Sudoku_Grid::elements_in_same_block_as(const size_t global) const noexcept
{
  const size_t first_element = number_of_rows_per_block_*number_of_cols_*global2rowblock(global)+number_of_cols_per_block_*global2colblock(global) ;
  vector<size_t> indices ;
  indices.reserve(number_of_cols_) ;
  for (size_t idx_first_col = first_element ; idx_first_col < first_element+number_of_rows_per_block_*number_of_cols_ ; idx_first_col += number_of_cols_)
  {
    for (size_t idx = idx_first_col ; idx < idx_first_col+number_of_cols_per_block_ ; idx++) indices.push_back(idx) ;
  }
  return indices ;
}
