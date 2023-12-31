#include "board.h"

using namespace std;

typedef struct Room
{
  string player_1;
  string player_2;
  bool player_1_accept_status;
  bool player_2_accept_status;
  int received_response = 0;
  string room_id;
  Board board;
  int player_turn;
  int game_state; // 0=paused 1=is playing 2=over
  list<Move> moves;
  string winner;
  Room(int width, int height, int win_condition, string _player_1, string _player_2, string _room_id)
  {
    player_turn = 1;
    board = Board(width, height, win_condition);
    player_1 = _player_1;
    player_2 = _player_2;
    room_id = _room_id;
    game_state = 1;
  }
  // 0 wrong logic  1-2 win 3 game is in pause state 4: player1 move 5: player2 move
  int play(int x, int y)
  {
    Move move = Move(x, y, player_turn);
    if (game_state == 0)
    {
      return 3;
    }
    if (board.move(move))
    {
      if (board.check_winner(move) == move.flag)
      {
        game_state = 2;
        if (player_turn == 1)
          winner = player_1;
        else
          winner = player_2;
        return move.flag;
      }
      player_turn = player_turn == 1 ? 2 : 1;
      return player_turn == 2 ? 4 : 5;
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
