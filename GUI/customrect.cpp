#include "customrect.h"
#include "token.h"
#include "../cmd.h"

void CustomRect::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!your_turn||value!=0||pause_state)
        return;
    your_turn = !your_turn;
    stringstream str_s_1;
    stringstream str_s_2;
    string move_x;
    string move_y;
    str_s_1 << x;
    str_s_1 >> move_x;
    str_s_2 << y;
    str_s_2 >> move_y;
    CMD cmd = CMD("CMD13",room_id,move_x.append("#").append(move_y));
    ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    QGraphicsRectItem::mousePressEvent(event);
}

