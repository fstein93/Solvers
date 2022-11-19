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
  Sudoku_Grid(const size_t number_of_rows_per_block=3, const size_t number_of_cols_per_block=3) : Square_Grid(number_of_rows_per_block*number_of_cols_per_block), number_of_rows_per_block_(number_of_rows_per_block), number_of_cols_per_block_(number_of_cols_per_block) {} ;
  // Convert global index to row/col/block numbers
  size_t global2rowblock(const size_t global) const {return global2row(global)/3 ;} ;
  size_t global2colblock(const size_t global) const {return global2col(global)/3 ;} ;
  size_t global2block(const size_t global) const {return 3*global2rowblock(global)+global2colblock(global) ;} ;
private:
  const size_t number_of_rows_per_block_, number_of_cols_per_block_ ;
};

#endif
