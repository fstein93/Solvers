#ifndef SQUARE_GRID_HPP
#define SQUARE_GRID_HPP

#include <vector>
#include <iostream>

// This object represents a square grid of fixed length
// and provides some helper routines to deal with coordinates
// The class assumes row-major order of the elements
template <typename T=size_t>
class Square_Grid
{
public:
  // Constructor
  constexpr Square_Grid(const T number_of_cols) noexcept : number_of_cols_(number_of_cols), number_of_fields_(number_of_cols*number_of_cols) {} ;
  // Convert global to local coordinates
  constexpr T global2row(const T global) const noexcept {return global/number_of_cols_ ;} ;
  constexpr T global2col(const T global) const noexcept {return global%number_of_cols_ ;} ;
  // Convert local to global coordinates
  constexpr T local2global(const T row, const T col) const noexcept {return row*number_of_cols_+col ;} ;
  // Getters
  constexpr T get_number_of_cols() const noexcept {return number_of_cols_ ;} ;
  constexpr T total_number_of_elements() const noexcept {return number_of_fields_ ;} ;
  // Determine indices of elements in the same row/col as the given element
  std::vector<T> elements_in_same_row_as(const T global) const noexcept 
  {
    std::vector<T> indices ;
    indices.reserve(number_of_cols_) ;
    const T first_element = first_element_in_row_of(global) ;
    for (T idx = first_element ; idx < first_element+number_of_cols_ ; idx++) indices.push_back(idx) ;
    return indices ;
  };
  std::vector<T> elements_in_same_col_as(const T global) const noexcept 
  {
    std::vector<T> indices ;
    indices.reserve(number_of_cols_) ;
    const T first_element = first_element_in_col_of(global) ;
    for (T idx = first_element ; idx < first_element+number_of_fields_ ; idx+=number_of_cols_) indices.push_back(idx) ;
    return indices ;
  };
  // Determine element in same row or columns as the given element
  std::vector<T> elements_in_same_row_or_col_as(const T global) const noexcept 
  {
    std::vector<T> indices(elements_in_same_row_as(global)) ;
    const T first_element = first_element_in_col_of(global) ;
    for (T idx = first_element ; idx < global ; idx+=number_of_cols_) indices.push_back(idx) ;
    for (T idx = global+number_of_cols_ ; idx < first_element+number_of_fields_ ; idx+=number_of_cols_) indices.push_back(idx) ;
    return indices ;
  };
  // First element in the same row/col/block as the element
  constexpr T first_element_in_row_of(const T global) const noexcept {return global-global2col(global) ;} ;
  constexpr T first_element_in_col_of(const T global) const noexcept {return global-global2row(global)*number_of_cols_ ;} ;
protected:
  const T number_of_cols_ ;
  const T number_of_fields_ ;
};

#endif
