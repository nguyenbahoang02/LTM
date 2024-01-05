#include "room.h"

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
  int connection_sock;
  int play;
  int win;
  Account()
  {
  }
  Account(string _username, string _password, char _status, int _elo, int _play, int _win)
  {
    username = _username;
    password = _password;
    status = _status;
    elo = _elo;
    play = _play;
    win = _win;
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
  list<Room> rooms;
  list<Room> history_rooms;
  void update_accounts_file()
  {
    FILE *f = fopen("account.txt", "w");
    for (Account &a : accounts)
    {
      fprintf(f, "%s %s %c %d %d %d\n", a.username.c_str(), a.password.c_str(), a.status, a.elo, a.play, a.win);
    }
    fclose(f);
  }
  int count_elo_gained(bool win, int player_1_elo, int player_2_elo, int player_1_win, int player_1_play)
  {
    int e;
    if (win)
    {
      if (player_1_elo != player_2_elo)
      {
        if (player_1_play == 0)
        {
          e = (int)((30 + (player_2_elo - player_1_elo) / abs(player_1_elo - player_2_elo) * log10(abs(player_1_elo - player_2_elo)) / log10(2)) * (1 + 0.5));
        }
        else
        {
          e = (int)((30 + (player_2_elo - player_1_elo) / abs(player_1_elo - player_2_elo) * log10(abs(player_1_elo - player_2_elo)) / log10(2)) * ((double)player_1_win / (double)player_1_play + 0.5));
        }
      }
      else
      {
        if (player_1_play == 0)
        {
          e = (int)((30) * (1 + 0.5));
        }
        else
        {
          e = (int)((30) * ((double)player_1_win / (double)player_1_play + 0.5));
        }
      }
    }
    else
    {
      if (player_1_elo != player_2_elo)
      {
        if (player_1_play == 0)
        {
          e = (int)((-30 + (player_2_elo - player_1_elo) / abs(player_1_elo - player_2_elo) * log10(abs(player_1_elo - player_2_elo)) / log10(2)) * (1.5 - 1));
        }
        else
        {
          e = (int)((-30 + (player_2_elo - player_1_elo) / abs(player_1_elo - player_2_elo) * log10(abs(player_1_elo - player_2_elo)) / log10(2)) * (1.5 - (double)player_1_win / (double)player_1_play));
        }
      }
      else
      {
        if (player_1_play == 0)
        {
          e = (int)((-30) * (1.5 - 1));
        }
        else
        {
          e = (int)((-30) * (1.5 - (double)player_1_win / (double)player_1_play));
        }
      }
    }
    return e;
  }
  void update_elo(string room_id)
  {
    Account *account_1;
    Account *account_2;
    for (Room r : rooms)
    {
      if (r.room_id == room_id)
      {
        for (Account &a : accounts)
        {
          if (a.username == r.player_1)
          {
            account_1 = &a;
          }
          if (a.username == r.player_2)
          {
            account_2 = &a;
          }
        }
        if (r.winner == r.player_1)
        {
          account_1->elo += count_elo_gained(true, account_1->elo, account_2->elo, account_1->win, account_1->play);
          account_1->play++;
          account_1->win++;
          account_2->elo += count_elo_gained(false, account_2->elo, account_1->elo, account_2->win, account_2->play);
          account_2->play++;
          if (account_2->elo < 0)
            account_2->elo = 0;
        }
        if (r.winner == r.player_2)
        {
          account_2->elo += count_elo_gained(true, account_2->elo, account_1->elo, account_2->win, account_2->play);
          account_2->play++;
          account_2->win++;
          account_1->elo += count_elo_gained(false, account_1->elo, account_2->elo, account_1->win, account_1->play);
          account_1->play++;
          if (account_1->elo < 0)
            account_1->elo = 0;
        }
        break;
      }
    }
  }
  Room find_room(string room_id)
  {
    for (Room r : rooms)
    {
      if (r.room_id == room_id)
        return r;
    }
  }
  Room find_history_room(string room_id)
  {
    for (Room r : history_rooms)
    {
      if (r.room_id == room_id)
        return r;
    }
  }
  void remove_room(string room_id)
  {
    list<Room> new_room_list;
    for (Room r : rooms)
    {
      if (r.room_id != room_id)
      {
        new_room_list.push_back(r);
      }
    }
  }
  void change_room_to_history_room(string room_id)
  {
    list<Room> new_room_list;
    for (Room r : rooms)
    {
      if (r.room_id != room_id)
      {
        new_room_list.push_back(r);
      }
      else
      {
        history_rooms.push_back(r);
      }
    }
    update_elo(room_id);
    rooms = new_room_list;
  }
  int make_a_move(string room_id, int x, int y)
  {
    for (Room &r : rooms)
    {
      if (r.room_id == room_id)
      {
        return r.play(x, y);
      }
    }
  }
  void set_player_accept_status(string room_id, string username, bool status)
  {
    for (Room &r : rooms)
    {
      if (r.room_id == room_id)
      {
        if (r.player_1 == username)
        {
          r.player_1_accept_status = status;
          r.received_response++;
        }
        else
        {
          r.player_2_accept_status = status;
          r.received_response++;
        }
        if (r.received_response == 2)
        {
          if (r.player_1_accept_status == true && r.player_2_accept_status == true)
          {
            send_message_to_account("CMD12_16$1?padding", r.player_1);
            send_message_to_account("CMD12_16$2?padding", r.player_2);
            return;
          }
          if (r.player_1_accept_status == true && r.player_2_accept_status == false)
          {
            char buff[128];
            strcpy(buff, "CMD11_");
            strcat(buff, r.player_2.c_str());
            strcat(buff, "?padding");
            send_message_to_account(buff, r.player_1);
          }
          if (r.player_1_accept_status == false && r.player_2_accept_status == true)
          {
            char buff[128];
            strcpy(buff, "CMD11_");
            strcat(buff, r.player_1.c_str());
            strcat(buff, "?padding");
            send_message_to_account(buff, r.player_2);
          }
          if (r.player_1_accept_status == false && r.player_2_accept_status == false)
          {
            char buff[128];
            strcpy(buff, "CMD11_");
            strcat(buff, r.player_1.c_str());
            strcat(buff, "?padding");
            send_message_to_account(buff, r.player_2);
            strcpy(buff, "CMD11_");
            strcat(buff, r.player_2.c_str());
            strcat(buff, "?padding");
            send_message_to_account(buff, r.player_1);
          }
          remove_room(r.room_id);
          return;
        }
        break;
      }
    }
  }
  void create_room(int width, int height, int win_condition, string _player_1, string _player_2, string room_id)
  {
    rooms.push_back(Room(width, height, win_condition, _player_1, _player_2, room_id));
  }
  string create_room(int width, int height, int win_condition, string _player_1, string _player_2)
  {
    string room_id = generate_token();
    rooms.push_back(Room(width, height, win_condition, _player_1, _player_2, room_id));
    return room_id;
  }
  string get_player_from_token(string token)
  {
    for (Account a : accounts)
    {
      if (a.token.token == token)
      {
        return a.username;
      }
    }
  }
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
  void log_out_account(int conn_sock)
  {
    for (Account &a : accounts)
    {
      if (a.connection_sock == conn_sock)
      {
        a.log_out();
      }
    }
  }
  // 0=wrong password token=login success 2=already logged in at another location
  string log_in_account(string username, string password, int conn_sock)
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
            a.connection_sock = conn_sock;
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
    Account new_acc = Account(username, password, '0', 0, 0, 0);
    accounts.push_back(new_acc);
    return 1;
  }
  void print_accounts()
  {
    for (Account a : accounts)
    {
      cout << a.username << "\t" << a.password << "\t" << a.status << "\t" << a.elo << endl;
    }
  }
  // send message to an account
  void send_message_to_account(char *message, int connect_sock)
  {
    cout << "Send: " << message << endl;
    send(connect_sock, message, strlen(message), 0);
  }
  void send_message_to_account(char *message, string username)
  {
    for (Account a : accounts)
    {
      if (a.username == username)
      {
        cout << "Send: " << message << endl;
        send(a.connection_sock, message, strlen(message), 0);
        return;
      }
    }
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
  list<Account> match_players()
  {
    list<Account> matched_players;
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
              matched_players.push_back(a);
              matched_players.push_back(b);
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
    int play;
    int win;
    if (f == NULL)
      return;
    while (fscanf(f, "%s %s %c %d %d %d", username, password, &status, &elo, &play, &win) == 6)
    {
      Account acc = Account(username, password, status, elo, play, win);
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
      if (a.token.token != token && a.status == '1')
      {
        online_players.push_back(a.username);
      }
    }
    return online_players;
  }
} AccountManager;
