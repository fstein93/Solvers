#include <vector>

class Sudoku
{
public:
  Sudoku() : board_(81) {} ;
  Sudoku(const size_t board[81]) : board_(board, board+81) {} ;
  void print() const ;
private:
  std::vector<size_t> board_ ;
};
