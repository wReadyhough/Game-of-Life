#include <iostream>
#include <fstream>
#include <chrono>

#include "board.h"

using namespace std;
using namespace std::chrono;

int main() {
  srand(time(NULL));
  ifstream myFile;
  myFile.open("file.txt");

  int numAlive, row;
  int column = 0;
  int numIterations = 100;
  string line;
  string fileVar = "";
  if(myFile.is_open()){
    while(getline(myFile, line)){
      fileVar+=line;
      fileVar+='|';
      row = line.length();
      column++;
    }
    boardClass myBoard(row, column, fileVar);
    myBoard.printBoard();
    myBoard.update();
    myBoard.printBoard();
    myBoard.update();
    myBoard.printBoard();
    myBoard.update();
    myBoard.printBoard();
  }
  else{
    
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
  myFile.close();
}


