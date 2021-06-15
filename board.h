#include <iostream>
#include <vector>

using namespace std;

class boardClass{
  int xDim, yDim;
  vector<vector<int>> theBoard;
  public:
    boardClass(int, int);
    void printBoard();

    vector<vector<int> > createBoard();
};
