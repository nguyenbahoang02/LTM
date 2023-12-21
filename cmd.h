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

typedef struct CMD
{
  string header;
  string body;
  int id;
  char cmd[1024];
  string token;
  void get_id()
  {
    id = (header[3] - '0') * 10;
    id += (header[4] - '0');
  }
  CMD()
  {
  }
  void get_token()
  {
    size_t pos = header.find("&");
    if (pos != string::npos)
    {
      token = header.substr(pos + 1);
    }
  }
  string extract_cmd(const std::string &input)
  {
    list<string> result;
    stringstream ss(input);
    string item;
    while (getline(ss, item, '?'))
    {
      result.push_back(item);
    }
    result.pop_back();
    return result.front();
  }
  // descontruct
  CMD(string _cmd)
  {
    string refined_cmd = extract_cmd(_cmd);
    size_t pos = _cmd.find("_");
    header = refined_cmd.substr(0, pos);
    body = refined_cmd.substr(pos + 1);
    strcpy(cmd, header.c_str());
    strcat(cmd, "_");
    strcat(cmd, body.c_str());
    strcat(cmd, "?");
    strcat(cmd, "padding");
    get_token();
    get_id();
  }
  // construct
  CMD(char _header[], char _body[])
  {
    header = "";
    header.append(_header);
    body = _body;
    strcpy(cmd, header.c_str());
    strcat(cmd, "_");
    strcat(cmd, body.c_str());
    strcat(cmd, "?");
    strcat(cmd, "padding");
    get_id();
  }
  // construct
  CMD(string _header, string _body)
  {
    header = _header;
    body = _body;
    strcpy(cmd, header.c_str());
    strcat(cmd, "_");
    strcat(cmd, body.c_str());
    strcat(cmd, "?");
    strcat(cmd, "padding");
    get_id();
  }
  // construct with token
  CMD(string _header, string _token, string _body)
  {
    header = _header;
    header.append("&");
    token = _token;
    header.append(token);
    body = _body;
    strcpy(cmd, header.c_str());
    strcat(cmd, "_");
    strcat(cmd, body.c_str());
    strcat(cmd, "?");
    strcat(cmd, "padding");
    get_id();
  }
} CMD;
