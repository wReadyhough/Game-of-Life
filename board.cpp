#include "board.h"

boardClass::boardClass(int x, int y){
  xDim = x;
  yDim = y;
  theBoard = createBoard();
}

void boardClass::printBoard(){
  for(int x = 0; x<theBoard.size(); x++){
    for(int y = 0; y <theBoard[x].size(); y++){
      cout<<theBoard[x][y];
    }
    cout<<endl;
  }
}

vector<vector<int> > boardClass::createBoard(){
  cout<<"A new board has been created!"<<endl;
  vector<vector<int> > theBoard;
  vector<int> temp;
  for(int x = 0; x < xDim; x++){
    for(int y = 0; y < yDim; y++){
      temp.push_back(0);
    }
    theBoard.push_back(temp);
    temp.clear();
  }
  return theBoard;
}