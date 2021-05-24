#include "players.h"


using namespace std;


void UserPlayer::play(Board& board, bool playerFlag){
  int x, y;
  if(playerFlag) cout << "oの番です。" << endl;
  else cout << "xの番です。" << endl;
  cout << "座標（x:0-" << board.getBoardSize() - 1 << ", y:0-" << board.getBoardSize() - 1 << "）を入力してください。x y:" << endl;
  cin >> x >> y;
  if(!board.setStone(x, y, playerFlag)){
    cout << "置く場所が不適切です。" << endl;
    play(board, playerFlag);
  }
}

void RandomPlayer::play(Board &board, bool playerFlag)
{
  random_device rnd;
  vector<int> emptySpaces;
  int position = 0;
  board.getEmptySpace(emptySpaces);
  position = emptySpaces[rnd() % emptySpaces.size()];
  board.setStone(position / 3, position % 3, playerFlag);
}