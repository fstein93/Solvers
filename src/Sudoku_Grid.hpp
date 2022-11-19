#ifndef SUDOKU_GRID_HPP
#define SUDOKU_GRID_HPP

#include "Square_Grid.hpp"

class Sudoku_Grid : public Square_Grid
{
public:
  Sudoku_Grid(const size_t number_of_rows_per_block=3, const size_t number_of_cols_per_block=3) : Square_Grid(number_of_rows_per_block*number_of_cols_per_block), number_of_rows_per_block_(number_of_rows_per_block), number_of_cols_per_block_(number_of_cols_per_block) {} ;
private:
  const size_t number_of_rows_per_block_, number_of_cols_per_block_ ;
};

#endif
