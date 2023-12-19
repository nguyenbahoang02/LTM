#include "DataReceiver.h".
#include "token.h"
#include <QThread>
#include "../cmd.h"
#define BUFF_SIZE 1024

DataReceiver::DataReceiver() {}
void DataReceiver::GetSignal() {

    char message[BUFF_SIZE];
    while(1){
        ::recv(server_sock, message, BUFF_SIZE - 1, 0);
        CMD cmd = CMD(message);
        switch(cmd.id)
        {
        case 1:
        {
            emit login_response_signal(message);
            break;
        }
        case 2: {
            emit signup_response_signal(message);
            break;
        }
        case 3:{
            emit logout_response_signal(message);
            break;
        }
        case 5:{
            emit player_list_signal(message);
            break;
        }
        case 6:{
            emit find_match_response_signal(message);
            break;
        }
        case 8:{
            emit player_list_signal(message);
            break;
        }
        }


    }
}
