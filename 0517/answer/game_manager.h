#include <iostream>
#include <vector>
#include "board.h"
#include "players.h"


class GameManager{
private:
  Board board;
  UserPlayer firstPlayer;
  RandomPlayer secondPlayer;
  bool playerFlag;

public:
  void run();
  void finishProcess();
};