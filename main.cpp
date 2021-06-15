#include <iostream>

#include "board.h"

using namespace std;
int main() {
  srand(time(NULL));
  int numAlive, row, column;
  row = 5;
  column = 6;
  boardClass myBoard(row,column);
  myBoard.printBoard();
  cout<<"How many cells do you want alive: ";
  cin>>numAlive;
  myBoard.addAliveCells(numAlive);
  cout<<"Board after randomly inserting "<<numAlive<<" alive cells: "<<endl;
  myBoard.printBoard();
  
}


