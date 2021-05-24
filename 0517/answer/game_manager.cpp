#include "game_manager.h"

using namespace std;

void GameManager::run(){
  bool isDone = false;
  bool playerFlag = true;
  while (!isDone){
    board.printBoard();
    if (playerFlag) firstPlayer.play(board, playerFlag);
    else secondPlayer.play(board, playerFlag);
    if (board.checkFinish()) isDone = true;
    playerFlag = !playerFlag;
  }
  finishProcess();
}

void GameManager::finishProcess(){
  cout << "結果" << endl;
  board.printBoard();
  int winner = board.getWinner();
  switch (winner)
  {
  case -1:
    cout << "xの勝ち" << endl;
    break;
  case 1:
    cout << "oの勝ち" << endl;
    break;
  default:
    cout << "引き分け" << endl;
    break;
  }
}