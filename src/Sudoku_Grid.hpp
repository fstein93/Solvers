#ifndef SUDOKU_GRID_HPP
#define SUDOKU_GRID_HPP

#include "Square_Grid.hpp"

// This class represents the grid of a Sudoku board
// and provides some helper routines
// The routines do not check whether the input coordinates are valid
class Sudoku_Grid : public Square_Grid
{
public:
  // Sudoku
  constexpr Sudoku_Grid(const size_t number_of_rows_per_block=3, const size_t number_of_cols_per_block=3) noexcept : Square_Grid(number_of_rows_per_block*number_of_cols_per_block), number_of_rows_per_block_(number_of_rows_per_block), number_of_cols_per_block_(number_of_cols_per_block) {} ;
  // Convert global index to coordinates of the block
  constexpr size_t global2rowblock(const size_t global) const noexcept {return global2row(global)/3 ;} ;
  constexpr size_t global2colblock(const size_t global) const noexcept {return global2col(global)/3 ;} ;
  constexpr size_t global2block(const size_t global) const noexcept {return 3*global2rowblock(global)+global2colblock(global) ;} ;
  // Function to loop over elements of a block of an element
  std::vector<size_t> elements_in_same_block_as(const size_t global) const noexcept ;
  // Function determines the index of the upper left element of the block of the given cell
  constexpr size_t first_element_in_block_of(const size_t global) const noexcept {return number_of_rows_per_block_*number_of_cols_*global2rowblock(global)+number_of_cols_per_block_*global2colblock(global) ;} ;
  // Function to determine the indices of all elements in the same row/block or col in as the given cell
  std::vector<size_t> elements_in_same_row_or_col_or_blk_as(const size_t global) const noexcept ;
private:
  const size_t number_of_rows_per_block_, number_of_cols_per_block_ ;
};

#endif
