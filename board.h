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
    boardClass(int, int, string);
    void printBoard();
    void addAliveCells(int);
    void createBoard();
    void createBoard(string);
    void update();
    bool aliveCheck(int, int);
    bool stillDeadCheck(int, int);
};
