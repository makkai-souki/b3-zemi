#include "board.h"

Board::Board(){
  boardSize = 3;
  vector<int> tmpRow;
  for(int i = 0; i < boardSize; i++) {
    for(int j = 0; j < boardSize; j++) {
      tmpRow.push_back(0);
    }
    field.push_back(tmpRow);
  }
  makeMask();
}

void Board::makeMask(){
  vector<int> tmpMask;
  for(int i = 0; i < boardSize; i++){
    for(int j = 0; j < boardSize; j++){
      tmpMask.push_back(i);
      tmpMask.push_back(j);
    }
    masks.push_back(tmpMask);
    tmpMask.clear();
  }
  for(int i = 0; i < boardSize; i++){
    vector<int> tmpMask;
    for(int j = 0; j < boardSize; j++){
      tmpMask.push_back(j);
      tmpMask.push_back(i);
    }
    masks.push_back(tmpMask);
    tmpMask.clear();
  }
  for(int i = 0; i < boardSize; i++){
    tmpMask.push_back(i);
    tmpMask.push_back(i);
  }
  masks.push_back(tmpMask);
  tmpMask.clear();
  for(int i = 0; i < boardSize; i++){
    tmpMask.push_back(i);
    tmpMask.push_back(boardSize - i - 1);
  }
  masks.push_back(tmpMask);
}

void Board::printBoard(){
  for(int i = 0; i < boardSize; i++) {
    for(int j = 0; j < boardSize; j++) {
      switch(field[i][j]){
        case 1:
          cout << "o";
          break;
        case -1:
          cout << "x";
          break;
        default:
          cout << "-";
          break;
      }
    }
    cout << endl;
  }
  cout << endl;
}

bool Board::isPlaceable(int x, int y){
  bool flag = false;
  if(x < 0 || x >= boardSize) return false;
  if(y < 0 || y >= boardSize) return false;
  if(field[x][y] == 0) return true;
  return false;
}


bool Board::checkFinish(){
  if(!existVacant()) return true;
  if(isWinner(1) || isWinner(-1)) return true;
  return false;
}

int Board::getBoardSize(){
  return boardSize;
}

bool Board::existVacant(){
  for(int i = 0; i < boardSize; i++){
    for(int j = 0; j < boardSize; j++){
      if(field[i][j] == 0){
        return true;
      }
    }
  }
  return false;
}

bool Board::setStone(int x, int y, bool playerFlag){
  if(isPlaceable(x, y)){
    if (playerFlag) field[x][y] = 1;
    else field[x][y] = -1;
    return true;
  }
  return false;
}

int Board::getWinner(){
  if(isWinner(-1)) return -1;
  if(isWinner(1)) return 1;
  return 0;
}

bool Board::isWinner(int player){
  bool flag = true;
  for(int i = 0; i < masks.size(); i++){
    flag = true;
    for(int j = 0; j < boardSize; j++){
      if(field[masks[i][j*2]][masks[i][j*2+1]] != player) {
        flag = false;
        break;
      }
    }
    if(flag) return true;
  }
  return false;
}

void Board::printMasks(){
  for(int i = 0; i < masks.size(); i++){
    for(int j=0; j < boardSize; j++){
      cout << "x" << j << ":" << masks[i][j*2] << "\t";
      cout << "y" << j << ":" << masks[i][j*2+1] << "\t";
    }
    cout << endl;
  }
}

void Board::getEmptySpace(vector<int>& emptySpaces){
  emptySpaces.clear();
  for(int i = 0; i < boardSize; i++){
    for(int j = 0; j < boardSize; j++){
      if(field[i][j] == 0){
        emptySpaces.push_back(3 * i + j);
      }
    }
  }
}