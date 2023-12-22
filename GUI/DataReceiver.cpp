#include "DataReceiver.h"
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
        cout << cmd.cmd << endl;
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
            emit received_challenge_signal(message);
            break;
        }
        case 9: {
            emit created_room_signal(message);
            emit create_board_signal(message);
            break;
        }
        case 10:{
            emit declined_challenge_signal(message);
            break;
        }
        case 11: {
            emit accept_find_match_signal(message);
            break;
        }
        case 12:{
            emit accept_find_match_signal(message);
            emit create_board_signal(message);
            break;
        }
        case 13:{
            emit update_board_signal(message);
            break;
        }
        }


    }
}
