#include <iostream>
#include <chrono>

#include "board.h"

using namespace std;
using namespace std::chrono;

int main() {
  srand(time(NULL));

  int numAlive, row, column;
  int numIterations = 100;
  cout<<"Enter how many rows/columns you want: ";
  cin>>row;
  column = row;
  cout<<"Enter how many alive cells you want("<<row*row<<" total spaces): ";
  cin>>numAlive;
  auto start = high_resolution_clock::now();
  for(int i = 0; i < numIterations; i++){
    boardClass myBoard(row,column);
    //myBoard.printBoard();
    /*cout<<"How many cells do you want alive: ";
    cin>>numAlive;*/
    myBoard.addAliveCells(numAlive);
    /*cout<<"Board after randomly inserting "<<numAlive<<" alive cells: "<<endl;
    myBoard.printBoard();
    cout<<"Board after updating: "<<endl;*/
    myBoard.update();
   /* myBoard.printBoard();
    cout<<"Board after updating again: "<<endl;*/
    myBoard.update();
    //myBoard.printBoard();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"On average, program took: "<<(((duration.count())/numIterations))<<" microseconds"<<endl;
  
}


