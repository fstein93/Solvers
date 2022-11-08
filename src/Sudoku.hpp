#include <vector>

class Sudoku
{
public:
  Sudoku() : board_(81) {} ;
  Sudoku(const size_t board[81]) ;
  void print() const ;
private:
  void check_sudoku() const ;
  std::vector<size_t> board_ ;
};
