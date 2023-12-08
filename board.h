#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

typedef struct Move
{
  int x;
  int y;
  int flag;
  Move(int _x, int _y, int _flag)
  {
    x = _x;
    y = _y;
    flag = _flag;
  }
} Move;

typedef struct Board
{
  int board[100][100]; // 1 is O 2 is x
  int width;
  int height;
  int win_condition;
  int move_count;
  Board()
  {
  }
  Board(int _width, int _height, int _win_condition)
  {
    width = _width;
    height = _height;
    win_condition = _win_condition;
    move_count = 0;
    for (int i = 1; i <= width; i++)
    {
      for (int j = 1; j <= height; j++)
      {
        board[i][j] = 0;
      }
    }
  }
  void print_board()
  {
    for (int i = 1; i <= width; i++)
    {
      for (int j = 1; j <= height; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
  bool in_board(int x, int y)
  {
    return 1 <= x && x <= width && 1 <= y && y <= height;
  }
  bool moveable(Move move)
  {
    return board[move.x][move.y] == 0 && in_board(move.x, move.y);
  }
  int check_winner(Move move) // 0 no one win 1 player 1 win 2 player 2 win
  {
    if (move_count < win_condition * 2 - 1)
    {
      return 0;
    }
    int check = 0;
    for (int i = 1; i <= height; i++) // check row
    {
      if (board[move.x][i] == move.flag)
      {
        check++;
        if (check == win_condition)
          return move.flag;
        continue;
      }
      check = 0;
    }
    check = 0;
    for (int i = 1; i <= width; i++) // check column
    {
      if (board[i][move.y] == move.flag)
      {
        check++;
        if (check == win_condition)
          return move.flag;
        continue;
      }
      check = 0;
    }
    int check_1 = 0;
    int check_2 = 0;
    for (int i = 0 - win_condition + 1; i <= win_condition - 1; i++)
    {
      if (in_board(move.x + i, move.y + i))
      {
        if (board[move.x + i][move.y + i] == move.flag)
        {
          check_1++;
          if (check_1 == win_condition)
            return move.flag;
        }
        else
        {
          check_1 = 0;
        }
      }
      if (in_board(move.x + i, move.y - i))
      {
        if (board[move.x + i][move.y - i] == move.flag)
        {
          check_2++;
          if (check_2 == win_condition)
            return move.flag;
        }
        else
        {
          check_2 = 0;
        }
      }
    }
    return 0;
  }
  bool move(Move move)
  {
    if (moveable(move))
    {
      board[move.x][move.y] = move.flag;
      move_count++;
      return true;
    }
    return false;
  }
} Board;
