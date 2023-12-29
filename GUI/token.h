#ifndef TOKEN_H
#define TOKEN_H
#include <QStackedWidget>

extern QStackedWidget *stackedWidget;
extern int server_sock;
extern std::string token;
extern std::string room_id;
extern int role;
extern bool your_turn;
extern bool pause_state;
#endif // TOKEN_H
