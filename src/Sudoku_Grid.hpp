#ifndef SUDOKU_GRID_HPP
#define SUDOKU_GRID_HPP

#include "Square_Grid.hpp"
#include <vector>

// This class represents the grid of a Sudoku board
// and provides some helper routines
// The routines do not check whether the input coordinates are valid
template <typename T>
class Sudoku_Grid : public Square_Grid<T>
{
  using uT = typename std::make_unsigned<T>::type ;
  static_assert(std::is_integral<T>::value, "Square_Grid requires an integral type") ;
public:
  // Sudoku
  constexpr Sudoku_Grid(const T number_of_rows_per_block=3, const T number_of_cols_per_block=3) noexcept : Square_Grid<T>(number_of_rows_per_block*number_of_cols_per_block), number_of_rows_per_block_(number_of_rows_per_block), number_of_cols_per_block_(number_of_cols_per_block) {} ;
  // Convert global index to coordinates of the block
  constexpr T global2rowblock(const T global) const noexcept {return this->global2row(global)/3 ;} ;
  constexpr T global2colblock(const T global) const noexcept {return this->global2col(global)/3 ;} ;
  constexpr T global2block(const T global) const noexcept {return 3*global2rowblock(global)+global2colblock(global) ;} ;
  // Function to loop over elements of a block of an element
  std::vector<T> elements_in_same_block_as(const T global) const noexcept 
  {
    const T first_element = first_element_in_block_of(global) ;
    std::vector<T> indices ;
    indices.reserve(this->number_of_cols_) ;
    for (T idx_first_col = first_element ; idx_first_col < first_element+number_of_rows_per_block_*this->number_of_cols_ ; idx_first_col += this->number_of_cols_)
    {
      for (T idx = idx_first_col ; idx < idx_first_col+number_of_cols_per_block_ ; idx++) indices.push_back(idx) ;
    }
    return indices ;
  };
  // Function determines the index of the upper left element of the block of the given cell
  constexpr T first_element_in_block_of(const T global) const noexcept {return number_of_rows_per_block_*this->number_of_cols_*global2rowblock(global)+number_of_cols_per_block_*global2colblock(global) ;} ;
  // Function to determine the indices of all elements in the same row/block or col in as the given cell
  std::vector<T> elements_in_same_row_or_col_or_blk_as(const T global) const noexcept 
  {
    std::vector<T> indices(this->elements_in_same_row_or_col_as(global)) ;
    const T first_element = first_element_in_block_of(global) ;
    for (const T& row : left_over_indices(this->global2row(global)%3, number_of_rows_per_block_))
    {
      for (const T& col : left_over_indices(this->global2col(global)%3, number_of_cols_per_block_))
      {
        indices.push_back(first_element + row*this->number_of_cols_ + col) ;
      }
    }
    return indices ;
  };
private:
  static std::vector<T> left_over_indices(const T index, const T max_idx) noexcept
  {
    std::vector<T> indices ;
    for (T idx = 0 ; idx < index ; idx++) indices.push_back(idx) ;
    for (T idx = index + 1 ; idx < max_idx ; idx++) indices.push_back(idx) ;
    return indices ;
  }
  const T number_of_rows_per_block_, number_of_cols_per_block_ ;
};

#endif
