#include "board.h"

boardClass::boardClass(int row, int column){
  xDim = column;
  yDim = row;
  createBoard();
}

void boardClass::printBoard(){
  for(int x = 0; x<theBoard.size(); x++){
    for(int y = 0; y <theBoard[x].size(); y++){
      cout<<theBoard[x][y].getAD();
    }
    cout<<endl;
  }
}

//xDim = # columns
void boardClass::createBoard(){
  cout<<"A new board has been created!"<<endl;
  vector<cell> temp;
  for(int row = 0; row < yDim; row++){
    for(int col = 0; col < xDim; col++){
      temp.push_back(cell(row,col));
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
    if(!theBoard[y][x].getAD()){
      numInserted++;
      theBoard[y][x].flipAD();
    }
  }
}

void boardClass::update(){
  vector<vector<int>> newBoard;
  vector<int> temp;
  for(int row = 0; row < theBoard.size(); row++){
    for(int col = 0; col < theBoard[row].size(); col++){
      temp.push_back(aliveCheck(row, col));
    }
    newBoard.push_back(temp);
    temp.clear();
  }

  //Copy newBoard into theBoard
  for(int row = 0; row < theBoard.size(); row++){
    for(int col = 0; col < theBoard[row].size(); col++){
      if(theBoard[row][col].getAD() != newBoard[row][col]){
        theBoard[row][col].flipAD();
      }
    }
  }
}


//row: 0-4
//col: 0-5
//Still alive if it has 2 or 3 neighbors
//Becomes alive if it has 3 neighbors
bool boardClass::aliveCheck(int row, int col){
  int numNeighbors = 0;

  int temp1, temp2;
  for(int i = 0; i < theBoard[row][col].getCols().size(); i++){
    temp1 = theBoard[row][col].getRows()[i];
    temp2 = theBoard[row][col].getCols()[i];
    (theBoard[temp1][temp2].getAD())? numNeighbors++ : numNeighbors+=0;
  }

  //Currently alive, return whether or not it still is
  if(theBoard[row][col].getAD()){
    return ((numNeighbors==2)||(numNeighbors==3))? 1 : 0;
  }

  //Currently dead, return whether or not it still is
  return(numNeighbors==3)? 1 : 0;
}


cell::cell(int row, int col){
  xDim = col;
  yDim = row;
  AD = 0;
  calcNeighbors();
}

cell::cell(){}

cell::~cell(){
  neighborRows.clear();
  neighborCols.clear();
}

int cell::getXDim(){
  return xDim;
}

int cell::getYDim(){
  return yDim;
}

int cell::getAD(){
  return AD;
}

//row: 0-4
//col: 0-5
void cell::calcNeighbors(){
  for(int x = -1; x < 2; x++){
    for(int y = -1; y < 2; y++){
      //keep in bounds
      if(xDim + x < 0 || xDim + x > 5){//col
        continue;
      }

      if(yDim + y < 0 || yDim + y > 4){//row
        continue;
      }

      //Not your own neighbor
      if(x == 0 && y == 0){
        continue;
      }
      neighborRows.push_back(yDim + y);
      neighborCols.push_back(xDim + x);
    }
  }
}

void cell::flipAD(){
  (AD)? AD = 0 : AD = 1;
}

vector<int> cell::getRows(){
  return neighborRows;
}
vector<int> cell::getCols(){
  return neighborCols;
}

void cell::displayNeigbors(){
  for(int i = 0;i<neighborCols.size();i++){
    cout<<"Neighbor at row: "<<neighborRows[i]<<" col: "<<neighborCols[i]<<endl;
  }
}