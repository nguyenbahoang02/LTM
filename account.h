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
  int elo;
  Account()
  {
  }
  Account(string _username, string _password, char _status, int _elo)
  {
    username = _username;
    password = _password;
    status = _status;
    elo = _elo;
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
  void log_out()
  {
    status = '0';
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

typedef struct AccountManager
{
  list<Account> accounts;
  list<Account> finding_match_players;
  bool check_user_token(string token)
  {
    for (Account &a : accounts)
    {
      if (a.token.token == token && a.token.check_valid())
      {
        return true;
      }
    }
    return false;
  }
  void log_out_account(string token)
  {
    for (Account &a : accounts)
    {
      if (a.token.token == token)
      {
        a.log_out();
      }
    }
  }
  // 0=wrong password 1=login success 2=already logged in at another location
  string log_in_account(string username, string password)
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
            return a.token.token;
          }
          return "2";
        }
        else
          return "0";
      }
    }
    return "0";
  }
  // 0=username exists 1=sign up success
  int sign_up_account(string username, string password)
  {
    for (Account a : accounts)
    {
      if (a.username == username)
        return 0;
    }
    Account new_acc = Account(username, password, '0', 0);
    accounts.push_back(new_acc);
    return 1;
  }
  void print_accounts()
  {
    for (Account a : accounts)
    {
      cout << a.username << "\t" << a.password << "\t" << a.status << endl;
    }
  }
  // send message to an account
  void send_message_to_account(char *message, int connect_sock)
  {
    send(connect_sock, message, strlen(message), 0);
  }
  void find_match(string token)
  {
    for (Account a : accounts)
    {
      if (a.token.token == token)
      {
        finding_match_players.push_back(a);
      }
    }
  }
  void remove_from_find_match(string username)
  {
    list<Account> list;
    for (Account a : finding_match_players)
    {
      if (a.username != username)
        list.push_back(a);
    }
    finding_match_players = list;
  }
  void cancel_find_match(string token)
  {
    list<Account> list;
    for (Account a : finding_match_players)
    {
      if (a.token.token != token)
        list.push_back(a);
    }
    finding_match_players = list;
  }
  list<string> match_players()
  {
    list<string> matched_players;
    int elo_gap = 100;
    while (1)
    {
      for (Account a : finding_match_players)
      {
        for (Account b : finding_match_players)
        {
          if (a.username != b.username)
          {
            if (abs(a.elo - b.elo) <= elo_gap)
            {
              matched_players.push_back(a.username);
              matched_players.push_back(b.username);
              remove_from_find_match(a.username);
              remove_from_find_match(b.username);
              return matched_players;
            }
          }
        }
      }
      if (matched_players.empty())
      {
        usleep(5000000);
        elo_gap += 50;
      }
    }
  }
  AccountManager(char *file)
  {
    FILE *f = fopen(file, "r");
    char username[1024];
    char password[1024];
    char status;
    int elo;
    if (f == NULL)
      return;
    while (fscanf(f, "%s %s %c %d", username, password, &status, &elo) == 4)
    {
      Account acc = Account(username, password, status, elo);
      accounts.push_back(acc);
    }
    fclose(f);
  }
  list<string> get_online_players(string token)
  {
    list<string> online_players;
    for (Account a : accounts)
    {
      if (a.status == '0')
        continue;
      if (a.token.token != token)
      {
        online_players.push_back(a.username);
      }
    }
    return online_players;
  }
} AccountManager;
