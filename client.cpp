#include "cmd.h"

#define BUFF_SIZE 1024

using namespace std;

int SERV_PORT;
char SERV_IP[100];
int client_sock;
char buff[BUFF_SIZE];
struct sockaddr_in server_addr;
int bytes_sent, bytes_received;

void print_menu()
{
  cout << "Menu:" << endl;
  cout << "1: Login" << endl;
  cout << "2: End" << endl;
}

void *sendThread(void *arg)
{
  while (1)
  {
    print_menu();
    memset(buff, '\0', (strlen(buff) + 1));
    cin >> buff;
    int code = 0;
    try
    {
      code = atoi(buff);
    }
    catch (const exception &e)
    {
    }
    switch (code)
    {
    case 1:
      memset(buff, '\0', (strlen(buff) + 1));
      char username[BUFF_SIZE];
      char password[BUFF_SIZE];
      cout << "Enter username: ";
      cin >> username;
      cout << "Enter password: ";
      cin >> password;
      strcpy(buff, username);
      strcat(buff, "#");
      strcat(buff, password);
      char cmd[1024];
      strcpy(cmd, CMD("01", buff).cmd);
      bytes_sent = send(client_sock, cmd, strlen(cmd) + 1, 0);
      break;
    case 2:
      close(client_sock);
      exit(0);
      break;
    default:
      break;
    }
  }
}

void *recvThread(void *arg)
{
  while (1)
  {
    memset(buff, '\0', (strlen(buff) + 1));
    bytes_received = recv(client_sock, buff, BUFF_SIZE - 1, 0);
    if (bytes_received < 0)
    {
      perror("Error: ");
      close(client_sock);
      return 0;
    }
    buff[bytes_received] = '\0';
    printf("%s\n", buff);
    if (buff[0] == 'G')
    {
      close(client_sock);
      exit(0);
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stdout, "Please enter required argument\n");
    return 0;
  }
  SERV_PORT = atoi(argv[2]);
  strcpy(SERV_IP, argv[1]);

  client_sock = socket(AF_INET, SOCK_STREAM, 0);

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERV_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERV_IP);

  if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
  {
    printf("\nError!Can not connect to sever! Client exit imediately! ");
    return 0;
  }

  pthread_t sendThreadID, recvThreadID;

  pthread_create(&sendThreadID, NULL, sendThread, &client_sock);
  pthread_create(&recvThreadID, NULL, recvThread, &client_sock);

  pthread_join(sendThreadID, NULL);
  pthread_join(recvThreadID, NULL);
}
