#include "room.h"
#include "cmd.h"

#define BUFF_SIZE 1024
#define BACKLOG 2

char buff[BUFF_SIZE];
int PORT;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
using namespace std;

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
  for (Account &a : accounts)
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
  for (Account &a : accounts)
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

void CMD_Handler(CMD cmd, int conn_sock);

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
      CMD_Handler(CMD(buff), conn_sock);
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

void CMD_Handler(CMD cmd, int conn_sock)
{
  switch (cmd.id)
  {
  case 1: // login
  {
    size_t pos_1 = cmd.body.find("#");
    string username_1 = cmd.body.substr(0, pos_1);
    string password_1 = cmd.body.substr(pos_1 + 1);
    pthread_mutex_lock(&lock);
    int login_result = login(username_1, password_1);
    pthread_mutex_unlock(&lock);
    switch (login_result)
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
