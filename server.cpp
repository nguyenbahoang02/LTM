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
#define BUFF_SIZE 8192
#define BACKLOG 2
char buff[BUFF_SIZE];

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

string generate_token()
{
  std::mt19937 generator(static_cast<unsigned int>(time(0)));

  // Define the characters that can be used in the random string
  const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

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

int main()
{
  get_accounts(&accounts);
  print_accounts(accounts);
}
