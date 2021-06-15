#include "board.h"

boardClass::boardClass(int row, int column){
  xDim = column;
  yDim = row;
  createBoard();
}

void boardClass::printBoard(){
  for(int x = 0; x<theBoard.size(); x++){
    for(int y = 0; y <theBoard[x].size(); y++){
      cout<<theBoard[x][y];
    }
    cout<<endl;
  }
}

//xDim = # columns
void boardClass::createBoard(){
  cout<<"A new board has been created!"<<endl;
  vector<int> temp;
  for(int row = 0; row < yDim; row++){
    for(int col = 0; col < xDim; col++){
      temp.push_back(0);
    }
    theBoard.push_back(temp);
    temp.clear();
  }
}

void boardClass::addAliveCells(int numAlive){

  int numInserted = 0;
  int x, y;

  while(numInserted<numAlive){
    //Generates the dimensions randomly
    x = rand() % (xDim); //column
    y = rand() % (yDim); //row
    if(!theBoard[y][x]){
      numInserted++;
      theBoard[y][x] = 1;
    }
  }
  cout<<"done"<<endl;
}