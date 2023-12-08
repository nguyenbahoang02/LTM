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
  void get_id()
  {
    id = (header[3] - '0') * 10;
    id += (header[4] - '0');
  }
  // descontruct
  CMD(string _cmd)
  {
    size_t pos = _cmd.find("_");
    header = _cmd.substr(0, pos);
    body = _cmd.substr(pos + 1);
    get_id();
  }
  // construct
  CMD(char _header[], char _body[])
  {
    header = "CMD";
    header.append(_header);
    body = _body;
    strcpy(cmd, header.c_str());
    strcat(cmd, "_");
    strcat(cmd, body.c_str());
    get_id();
  }
} CMD;
