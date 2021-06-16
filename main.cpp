#include <iostream>
#include <chrono>

#include "board.h"

using namespace std;
using namespace std::chrono;

int main() {
  srand(time(NULL));
  auto start = high_resolution_clock::now();
  int numAlive, row, column;
  row = 5;
  column = 6;
  int numIterations = 1000;
  for(int i = 0; i < numIterations; i++){
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
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"On average, program took: "<<(duration.count()/numIterations)<<" microseconds"<<endl;
  
}


