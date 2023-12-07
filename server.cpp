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

#define BUFF_SIZE 1024
#define BACKLOG 2

char buff[BUFF_SIZE];
int PORT;
using namespace std;

string generate_token();

typedef struct Token
{
  string token;
  std::chrono::high_resolution_clock::time_point creation_time;
  Token()
  {
    token = generate_token();
    creation_time = std::chrono::high_resolution_clock::now();
  }
  bool check_valid()
  {
    auto current_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::hours>(current_time - creation_time);
    return duration.count() < 4;
  }
} Token;

typedef struct Account
{
  string username;
  string password;
  char status; // 0=okay to login 1=already logged in at another location 2=ingame
  Token token;
  Account()
  {
  }
  Account(string _username, string _password, char _status)
  {
    username = _username;
    password = _password;
    status = _status;
  }
  bool is_login()
  {
    return status == '1' || status == '2';
  }
  void login()
  {
    status = '1';
    token = Token();
  }
  void logout()
  {
    status = '0';
  }
} Account;

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

typedef struct Room
{
  Account *player_1;
  Account *player_2;
  string room_id;
  Board board;
  int player_turn;
  int game_state; // 0=paused 1=is playing 2=over
  Room(int width, int height, int win_condition, Account *_player_1, Account *_player_2)
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

list<Account> accounts;

void get_accounts(list<Account> *accounts)
{
  FILE *f = fopen("account.txt", "r");
  char username[1024];
  char password[1024];
  char status;
  if (f == NULL)
    return;
  while (fscanf(f, "%s %s %c ", username, password, &status) == 3)
  {
    Account acc = Account(username, password, status);
    accounts->push_back(acc);
  }
  fclose(f);
}

int login(string username, string password) // 0=wrong password 1=login success 2=already logged in at another location
{
  for (Account a : accounts)
  {
    if (a.username == username)
    {
      if (a.password == password)
      {
        if (!a.is_login())
        {
          a.login();
          return 1;
        }
        return 2;
      }
      else
        return 0;
    }
  }
  return 0;
}

void logout(string username)
{
  for (Account a : accounts)
  {
    if (a.username == username)
    {
      a.status = '0';
    }
  }
}

int sign_up(string username, string password) // 0=username exists 1=sign up success
{
  for (Account a : accounts)
  {
    if (a.username == username)
      return 0;
  }
  Account new_acc = Account(username, password, '0');
  return 1;
}

void print_accounts(list<Account> accounts)
{
  for (Account a : accounts)
  {
    cout << a.username << "\t" << a.password << "\t" << a.status << endl;
  }
}

void CMD_Handler(string cmd, int conn_sock);
int CMD(string header);

void *handle_client(void *connect_sock)
{
  pthread_detach(pthread_self());
  int bytes_sent, bytes_received;
  int conn_sock = *((int *)connect_sock);
  while (1)
  {
    memset(buff, '\0', (strlen(buff) + 1));
    bytes_received = recv(conn_sock, buff, BUFF_SIZE - 1, 0);
    if (bytes_received < 0)
      perror("\nError: ");
    else
    {
      cout << buff << endl;
      CMD_Handler(buff, conn_sock);
    }
  }
}

int main(int argc, char *argv[])
{
  get_accounts(&accounts);
  pthread_t client_thread;
  if (argc != 2)
  {
    fprintf(stdout, "Please enter port number\n");
    return 0;
  }
  PORT = atoi(argv[1]);
  // Test board
  // Board board = Board(10, 10, 5);
  // while (1)
  // {
  //   cout << "Nguoi choi 1 di: " << endl;
  //   int x, y;
  //   cin >> x >> y;
  //   board.move(Move(x, y, 1));
  //   board.print_board();
  //   if (board.check_winner(Move(x, y, 1)) != 0)
  //   {
  //     cout << "Nguoi choi 1 thang" << endl;
  //     break;
  //   }
  //   cout << "Nguoi choi 2 di: " << endl;
  //   cin >> x >> y;
  //   board.move(Move(x, y, 2));
  //   board.print_board();
  //   if (board.check_winner(Move(x, y, 2)) != 0)
  //   {
  //     cout << "Nguoi choi 2 thang" << endl;
  //     break;
  //   }
  // }
  int listen_sock, conn_sock;
  struct sockaddr_in server;
  struct sockaddr_in client;

  if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("\nError: 1");
    exit(0);
  }

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  bzero(&(server.sin_zero), 8);

  if (bind(listen_sock, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
  {
    perror("\nError: 2");
    exit(0);
  }

  if (listen(listen_sock, BACKLOG) == -1)
  {
    perror("\nError: 3");
    return 0;
  }

  while (1)
  {
    socklen_t sin_size = sizeof(struct sockaddr_in);
    if ((conn_sock = accept(listen_sock, (struct sockaddr *)&client, &sin_size)) == -1)
      perror("\nError: 4");
    {
      printf("You got a connection from %s\n", inet_ntoa(client.sin_addr));
      pthread_create(&client_thread, NULL, &handle_client, (void *)&conn_sock);
    }
  }
  close(listen_sock);
}

int CMD(string header)
{
  int cmd = (header[3] - '0') * 10;
  cmd += (header[4] - '0');
  return cmd;
}

void CMD_Handler(string cmd, int conn_sock)
{
  size_t pos = cmd.find("_");
  string header = cmd.substr(0, pos);
  string body = cmd.substr(pos + 1);
  int cmd_id = CMD(header);
  cout << cmd_id << endl;
  switch (cmd_id)
  {
  case 1: // login
  {
    size_t pos_1 = body.find("#");
    string username_1 = body.substr(0, pos_1);
    string password_1 = body.substr(pos_1 + 1);
    switch (login(username_1, password_1))
    {
    case 0: // 0 wrong password
      break;
    case 1: // 1 login success
      break;
    case 2: // 2 already logged in
      break;
    }
    break;
  }
  case 2: // sign up
  {
    break;
  }
  case 3: // log out
  {
    break;
  }
  case 4: // change password
  {
    break;
  }
  }
}

string generate_token()
{
  mt19937 generator(static_cast<unsigned int>(time(0)));

  // Define the characters that can be used in the random string
  const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  // Create a distribution for the random index
  uniform_int_distribution<> distribution(0, characters.size() - 1);

  // Generate the random string
  string token;
  for (int i = 0; i < 10; ++i)
  {
    token += characters[distribution(generator)];
  }

  return token;
}
