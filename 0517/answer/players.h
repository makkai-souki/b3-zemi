#include <iostream>
#include <vector>
#include <random>
#include "board.h"


class UserPlayer
{
public:
  void play(Board& board, bool playerFlag);
};

class RandomPlayer
{
public:
  void play(Board &board, bool playerFlag);
};