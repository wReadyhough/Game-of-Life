#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h>       

using namespace std;

class cell{
  int AD;// Alive or Dead. 1 for alive;
  int xDim, yDim; //XDim = columns
  vector<int> neighborRows;
  vector<int> neighborCols;

  public:
    cell(int, int);
    cell();
    ~cell();
    int getXDim();
    int getYDim();
    int getAD();
    vector<int> getRows();
    vector<int> getCols();
    void flipAD();
    void calcNeighbors();
    void displayNeigbors();
};


class boardClass: public cell{
  int xDim, yDim;
  vector<vector<cell>> theBoard;
  public:
    boardClass(int, int);
    void printBoard();
    void addAliveCells(int);
    void createBoard();
    void update();
    bool aliveCheck(int, int);
    bool stillDeadCheck(int, int);
};

