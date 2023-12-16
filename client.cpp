#include "cmd.h"

#define BUFF_SIZE 1024

using namespace std;

int SERV_PORT;
char SERV_IP[100];
int client_sock;
char buff[BUFF_SIZE];
struct sockaddr_in server_addr;
int bytes_sent, bytes_received;
string token = "1";

void *sendThread(void *arg)
{
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
  strcpy(cmd, CMD("CMD01", buff).cmd);
  bytes_sent = send(client_sock, cmd, strlen(cmd), 0);
  while (1)
  {
    int a;
    cin >> a;
    break;
  }
  string message = "CMD06&";
  message.append(token);
  cout << token;
  message.append("_");
  message.append("1");
  send(client_sock, message.c_str(), 18, 0);
  while (1)
  {
  }
}

void *recvThread(void *arg)
{
  while (1)
  {
    char response[BUFF_SIZE];
    memset(response, '\0', strlen(response) + 1);
    bytes_received = recv(client_sock, response, BUFF_SIZE - 1, 0);
    if (bytes_received < 0)
    {
      perror("Error: ");
      close(client_sock);
      return 0;
    }
    response[bytes_received] = '\0';
    cout << response << endl;
    CMD cmd = CMD(response);
    if (cmd.id == 1)
    {
      token = cmd.token;
      cout << token << endl;
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
