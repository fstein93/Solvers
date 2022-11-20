#ifndef SQUARE_GRID_HPP
#define SQUARE_GRID_HPP

#include <vector>

// This object represents a square grid of fixed length
// and provides some helper routines to deal with coordinates
// The class assumes row-major order of the elements
class Square_Grid
{
public:
  // Constructor
  constexpr Square_Grid(const size_t number_of_cols) noexcept : number_of_cols_(number_of_cols), number_of_fields_(number_of_cols*number_of_cols) {} ;
  // Convert global to local coordinates
  constexpr size_t global2row(const size_t global) const noexcept {return global/number_of_cols_ ;} ;
  constexpr size_t global2col(const size_t global) const noexcept {return global%number_of_cols_ ;} ;
  // Convert local to global coordinates
  constexpr size_t local2global(const size_t row, const size_t col) const noexcept {return row*number_of_cols_+col ;} ;
  // Getters
  constexpr size_t get_number_of_cols() const noexcept {return number_of_cols_ ;} ;
  constexpr size_t total_number_of_elements() const noexcept {return number_of_fields_ ;} ;
  // Determine indices of elements in the same row/col as the given element
  std::vector<size_t> elements_in_same_row_as(const size_t global) const noexcept ;
  std::vector<size_t> elements_in_same_col_as(const size_t global) const noexcept ;
protected:
  const size_t number_of_cols_ ;
  const size_t number_of_fields_ ;
};

#endif
