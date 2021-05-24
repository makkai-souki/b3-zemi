#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Board{
private:
  vector<vector<int> > field;
  vector<vector<int> > masks;
  int boardSize;

public:
  Board();
  void printBoard();
  bool isPlaceable(int x, int y);
  bool checkFinish();
  void makeMask();
  bool existVacant();
  int getBoardSize();
  bool setStone(int x, int y, bool playerFlag);
  int getWinner();
  void printMasks();
  void getEmptySpace(vector<int>& emptySpaces);
  bool isWinner(int player);
};
