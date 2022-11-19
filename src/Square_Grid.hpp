#ifndef SQUARE_GRID_HPP
#define SQUARE_GRID_HPP

// This object represents a square grid of fixed length
// and provides some helper routines to deal with coordinates
// The class assumes row-major order of the elements
class Square_Grid
{
public:
  // Constructor
  Square_Grid(const size_t number_of_cols) : number_of_cols_(number_of_cols), number_of_fields_(number_of_cols*number_of_cols) {} ;
  // Convert global to local coordinates
  size_t global2row(const size_t global) const {return global/number_of_cols_ ;} ;
  size_t global2col(const size_t global) const {return global%number_of_cols_ ;} ;
  // Convert local to global coordinates
  size_t local2global(const size_t row, const size_t col) const {return row*number_of_cols_+col ;} ;
  // Getters
  size_t get_number_of_cols() const {return number_of_cols_ ;} ;
  size_t total_number_of_elements() const {return number_of_fields_ ;} ;
protected:
  const size_t number_of_cols_ ;
  const size_t number_of_fields_ ;
};

#endif
