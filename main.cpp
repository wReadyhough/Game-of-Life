#include <iostream>
#include <chrono>

#include "board.h"

using namespace std;
using namespace std::chrono;

int main() {
  auto total = 0;
  int numIterations = 100;
  
  srand(time(NULL));
  int numAlive, row, column;
  cout<<"Enter number of rows/columns: ";
  cin>>row;
  column = row;
  cout<<"Enter number of alive cells("<<row*row<<" total spaces): ";
  cin>>numAlive;
  auto start = high_resolution_clock::now();
  for(int i = 0; i < numIterations; i++){
    boardClass myBoard(row,column);
    //myBoard.printBoard();
    myBoard.addAliveCells(numAlive);
   /* cout<<"Board after randomly inserting "<<numAlive<<" alive cells: "<<endl;
    myBoard.printBoard();
    cout<<"Board after updating: "<<endl;*/
    myBoard.update();
    myBoard.update();
    //myBoard.printBoard();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"Average program time: "<<(duration.count())/numIterations<<" microseconds"<<endl;
  
}


