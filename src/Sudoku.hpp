#include <vector>

class Sudoku
{
public:
  Sudoku() : board(81) {} ;
  void print() const ;
private:
  std::vector<size_t> board ;
};
