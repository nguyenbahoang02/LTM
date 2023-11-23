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
#define BUFF_SIZE 8192
#define BACKLOG 2
char buff[BUFF_SIZE];

using namespace std;

typedef struct
{
  char username[1024];
  char password[1024];
  char status;
} Account;

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
    Account acc;
    strcpy(acc.username, username);
    strcpy(acc.password, password);
    acc.status = status;
    accounts->push_back(acc);
  }
  fclose(f);
}

void print_accounts(list<Account> accounts)
{
  for (Account a : accounts)
  {
    cout << a.username << endl;
  }
}

int main()
{
  list<Account> accounts;
  get_accounts(&accounts);
  print_accounts(accounts);
}
