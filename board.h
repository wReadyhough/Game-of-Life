#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h>       

using namespace std;

class boardClass{
  int xDim, yDim;
  vector<vector<int>> theBoard;
  public:
    boardClass(int, int);
    void printBoard();
    void addAliveCells(int);
    void createBoard();
    void update();
    bool aliveCheck(int, int);
    bool stillDeadCheck(int, int);
};
