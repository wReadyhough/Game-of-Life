#include "board.h"

boardClass::boardClass(int row, int column){
  xDim = column;
  yDim = row;
  createBoard();
}

boardClass::boardClass(int row, int column, string file){
  xDim = column;
  yDim = row;
  createBoard(file);
}

int boardClass::getNumAlive(){
  return numAlive;
}

void boardClass::printBoard(){
  system("clear");
  for(int x = 0; x<theBoard.size(); x++){
    for(int y = 0; y <theBoard[x].size(); y++){
      cout<<((theBoard[x][y])? ("1") :("-"));
      //cout<<theBoard[x][y];
    }
    cout<<endl;
  }
  cout<<endl;
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

void boardClass::createBoard(string file){
  cout<<"A new file has been created from a file!"<<endl;
  vector<int> temp;
  for(int i = 0; i<file.length(); i++){
    if(file[i]=='|'){
      theBoard.push_back(temp);
      temp.clear();
    }
    else{
      temp.push_back(int(file[i] - '0'));
      if(file[i]=='1'){
        numAlive++;
      }
    }
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
      theBoard[row][col] = newBoard[row][col];
    }
  }
}


//row: 0-4
//col: 0-5
//Still alive if it has 2 or 3 neighbors
//Becomes alive if it has 3 neighbors
bool boardClass::aliveCheck(int row, int col){
  int numNeighbors = 0;
  for(int x = -1; x < 2; x++){
    for(int y = -1; y <2; y++){
      //staying in bounds.
      if((row+x)<0 || (row+x)>=yDim){
        continue;
      }
      if((col+y)<0||(col+y)>xDim){
        continue;
      }

      //you are not your own neighbor
      if(y ==0 && x == 0){
        continue;
      }
      //This neighbor is alive, increment # of neighbors
      //Otherwise, add 0 to numNeighbors

      (theBoard[row+x][col+y])? numNeighbors++ : numNeighbors+=0;
    }
  }
  //cout<<"cell at row "<<row<<" col "<<col<<" has "<<numNeighbors<<" alive neighbors"<<endl;
  //Currently alive, return whether or not it still is
  //cout<<"Cell at row "<<row<<" col "<<col<<" has "<<numNeighbors<<" alive neighbors."<<endl;
  if(theBoard[row][col]){

    //dies.
    if((numNeighbors!=2)&&numNeighbors != 3){
      numAlive--;
    }    
    return ((numNeighbors==2)||(numNeighbors==3))? 1 : 0;
  }

  //Currently dead, return whether or not it still is
  //Becomes alive
  if(numNeighbors == 3){
    numAlive++;
  }
  return(numNeighbors==3)? 1 : 0;
}

