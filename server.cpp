#include "cmd.h"
#include "account.h"
#define BUFF_SIZE 1024
#define BACKLOG 2

char buff[BUFF_SIZE];
int PORT;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
using namespace std;

AccountManager account_manager = AccountManager("account.txt");

void CMD_Handler(CMD cmd, int conn_sock);

void *handle_room(void *arg)
{
  list<Account> matched_players = *((list<Account> *)arg);
  Account player_1 = matched_players.back();
  Account player_2 = matched_players.front();
}

void *handle_match(void *arg)
{
  while (1)
  {
    if (account_manager.finding_match_players.size() < 2)
    {
      usleep(5000000);
      continue;
    }
    list<Account> matched_players = account_manager.match_players();
    CMD cmd = CMD("CMD06", "FOUND_A_MATCH");
    for (Account s : matched_players)
    {
      account_manager.send_message_to_account(cmd.cmd, s.connection_sock);
    }
    pthread_t room_thread;
    pthread_create(&room_thread, NULL, &handle_room, (void *)&matched_players);
  }
}

void *handle_client(void *connect_sock)
{
  pthread_detach(pthread_self());
  int bytes_sent, bytes_received;
  int conn_sock = *((int *)connect_sock);
  while (1)
  {
    memset(buff, '\0', (strlen(buff) + 1));
    bytes_received = recv(conn_sock, buff, BUFF_SIZE - 1, 0);
    if (bytes_received <= 0)
    {
      close(conn_sock);
      break;
    }
    else
    {
      cout << buff << endl;
      CMD_Handler(CMD(buff), conn_sock);
    }
  }
  pthread_exit(connect_sock);
}

int main(int argc, char *argv[])
{
  pthread_t client_thread;
  if (argc != 2)
  {
    fprintf(stdout, "Please enter port number\n");
    return 0;
  }
  PORT = atoi(argv[1]);
  pthread_create(&client_thread, NULL, &handle_match, NULL);
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

void CMD_Handler(CMD cmd, int conn_sock)
{
  CMD response_cmd;
  switch (cmd.id)
  {
  case 1: // login
  {
    size_t pos = cmd.body.find("#");
    string username = cmd.body.substr(0, pos);
    string password = cmd.body.substr(pos + 1);
    pthread_mutex_lock(&lock);
    string login_result = account_manager.log_in_account(username, password, conn_sock);
    pthread_mutex_unlock(&lock);
    if (login_result == "0")
    {
      response_cmd = CMD(cmd.header, "WRONG_PASSWORD\0");
    }
    else if (login_result == "2")
    {
      response_cmd = CMD(cmd.header, "ACCOUNT_ALREADY_LOGGED_IN_AT_ANOTHER_LOCATION\0");
    }
    else
    {
      response_cmd = CMD(cmd.header.append("&").append(login_result), "LOGIN_SUCCESSFULLY\0");
    }
    account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
    break;
  }
  case 2: // sign up
  {
    size_t pos = cmd.body.find("#");
    string username = cmd.body.substr(0, pos);
    string password = cmd.body.substr(pos + 1);
    pthread_mutex_lock(&lock);
    int sign_up_result = account_manager.sign_up_account(username, password);
    pthread_mutex_unlock(&lock);
    switch (sign_up_result)
    {
    case 0: // username exist
    {
      response_cmd = CMD(cmd.header, "USERNAME_EXISTS\0");
    }
    break;
    case 1:
    {
      response_cmd = CMD(cmd.header, "SIGN_UP_SUCCESS\0");
      break;
    }
    }
    account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
    break;
  }
  case 3: // log out
  {
    pthread_mutex_lock(&lock);
    account_manager.log_out_account(cmd.body);
    pthread_mutex_unlock(&lock);
    response_cmd = CMD(cmd.header, "LOG_OUT_SUCCESSFULLY\0");
    account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
    break;
  }
  case 4: // change password
  {
    break;
  }
  case 5: // get online players
  {
    bool check_valid = account_manager.check_user_token(cmd.token);
    if (!check_valid)
    {
      response_cmd = CMD(cmd.header, "0");
      account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
      break;
    }
    list<string> users = account_manager.get_online_players(cmd.token);
    string list_players = "";
    for (string u : users)
    {
      list_players.append(u);
      list_players.append("$");
    }
    if (list_players == "")
      list_players.append("@");
    list_players.append("\0");
    response_cmd = CMD(cmd.header, list_players);
    account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
    break;
  }
  case 6: // find a match
  {
    bool check_valid = account_manager.check_user_token(cmd.token);
    if (!check_valid)
    {
      response_cmd = CMD(cmd.header, "0");
      account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
      break;
    }
    pthread_mutex_lock(&lock);
    account_manager.find_match(cmd.token);
    pthread_mutex_unlock(&lock);
    break;
  }
  case 7: // cancel find match
  {
    bool check_valid = account_manager.check_user_token(cmd.token);
    if (!check_valid)
    {
      response_cmd = CMD(cmd.header, "0");
      account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
      break;
    }
    pthread_mutex_lock(&lock);
    account_manager.cancel_find_match(cmd.token);
    pthread_mutex_unlock(&lock);
    break;
  }
  case 8: // send challenge
  {
    bool check_valid = account_manager.check_user_token(cmd.token);
    if (!check_valid)
    {
      response_cmd = CMD(cmd.header, "0");
      account_manager.send_message_to_account(response_cmd.cmd, conn_sock);
      break;
    }

    break;
  }
  case 9: // make a move
  {

    break;
  }
  case 10: // pause/continue game
  {

    break;
  }
  case 11: // get record
  {

    break;
  }
  case 12:
  {

    break;
  }
  }
  account_manager.print_accounts();
}
