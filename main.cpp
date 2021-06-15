#include <iostream>

#include "board.h"

using namespace std;
int main() {
  //srand(time(NULL));
  srand(1);
  int numAlive, row, column;
  row = 5;
  column = 6;
  boardClass myBoard(row,column);
  myBoard.printBoard();
  /*cout<<"How many cells do you want alive: ";
  cin>>numAlive;*/
  numAlive = 10;
  myBoard.addAliveCells(numAlive);
  cout<<"Board after randomly inserting "<<numAlive<<" alive cells: "<<endl;
  myBoard.printBoard();
  cout<<"Board after updating: "<<endl;
  myBoard.update();
  myBoard.printBoard();
  
}


