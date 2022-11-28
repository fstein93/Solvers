#include <stddef.h>
#include <vector>
#include "Square_Grid.hpp"

#include <iostream>

using namespace std ;

vector<size_t> Square_Grid::elements_in_same_row_as(const size_t global) const noexcept
{
  vector<size_t> indices ;
  indices.reserve(number_of_cols_) ;
  const size_t first_element = first_element_in_row_of(global) ;
  for (size_t idx = first_element ; idx < first_element+number_of_cols_ ; idx++) indices.push_back(idx) ;
  return indices ;
}

vector<size_t> Square_Grid::elements_in_same_col_as(const size_t global) const noexcept
{
  vector<size_t> indices ;
  indices.reserve(number_of_cols_) ;
  const size_t first_element = first_element_in_col_of(global) ;
  for (size_t idx = first_element ; idx < first_element+number_of_fields_ ; idx+=number_of_cols_) indices.push_back(idx) ;
  return indices ;
}
