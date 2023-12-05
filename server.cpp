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

typedef struct Account
{
  string username;
  string password;
  char status; // 0=okay to login 1=already logged in at another location
  Account(string _username, string _password, char _status)
  {
    username = _username;
    password = _password;
    status = _status;
  }
} Account;

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

list<Account> accounts;
list<Token> tokens;

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
        if (a.status == '0')
        {
          a.status = '1';
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
  case 1:
  {
    size_t pos_1 = body.find("#");
    string username_1 = body.substr(0, pos_1);
    string password_1 = body.substr(pos_1 + 1);

    break;
  }
  }
}
