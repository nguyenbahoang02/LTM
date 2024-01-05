#include "gamescene.h"
#include "../cmd.h"

using namespace std;

void GameScene::update_board(string message){
    CMD response_cmd = CMD(message);
    size_t pos_1 = response_cmd.body.find("$");
    string move = response_cmd.body.substr(0,pos_1);
    string role_str = response_cmd.body.substr(pos_1+1);
    int role_int = atoi(role_str.c_str());
    size_t pos_2 = move.find("#");
    string move_x = move.substr(0,pos_2);
    string move_y = move.substr(pos_2+1);
    int x = atoi(move_x.c_str());
    int y = atoi(move_y.c_str());
    tile[x][y]->value = role_int;
    if(role_int==1){
        add_O(x,y,tile[x][y]->tile_size);
    }else{
        add_X(x,y,tile[x][y]->tile_size);
    }
}
