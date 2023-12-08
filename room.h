#include "board.h"
#include "account.h"

using namespace std;

typedef struct Room
{
  Account player_1;
  Account player_2;
  string room_id;
  Board board;
  int player_turn;
  int game_state; // 0=paused 1=is playing 2=over
  Room(int width, int height, int win_condition, Account _player_1, Account _player_2)
  {
    player_turn = 1;
    board = Board(width, height, win_condition);
    player_1 = _player_1;
    player_2 = _player_2;
    game_state = 1;
  }
  // 0 wrong logic  1-2 win 3 moveable 4 game is in pause state
  int play(int x, int y)
  {
    Move move = Move(x, y, player_turn);
    if (game_state == 0)
    {
      return 4;
    }
    if (board.move(move))
    {
      if (board.check_winner(move) == move.flag)
      {
        game_state = 2;
        return move.flag;
      }
      player_turn = player_turn == 1 ? 2 : 1;
      return 3;
    }
    return 0;
  }
  void pause()
  {
    game_state = 0;
  }
  void un_pause()
  {
    game_state = 1;
  }
} Room;
