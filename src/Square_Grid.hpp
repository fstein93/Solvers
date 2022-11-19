#ifndef SQUARE_GRID_HPP
#define SQUARE_GRID_HPP

class Square_Grid
{
public:
  Square_Grid(const size_t number_of_cols) : number_of_cols_(number_of_cols), number_of_fields_(number_of_cols*number_of_cols) {} ;
  size_t global2row(const size_t global) const {return global/number_of_cols_ ;} ;
  size_t global2col(const size_t global) const {return global%number_of_cols_ ;} ;
  size_t get_number_of_cols() const {return number_of_cols_ ;} ;
  size_t total_number_of_elements() const {return number_of_fields_ ;} ;
protected:
  const size_t number_of_cols_ ;
  const size_t number_of_fields_ ;
};

#endif
