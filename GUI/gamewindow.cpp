#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "../cmd.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDebug>
#include "token.h"
#include "gamescene.h"

using namespace std;

int role;
bool your_turn;
bool pause_state;

gamewindow::gamewindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gamewindow)
{
    ui->setupUi(this);
}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::handle_create_match_response(string message){
    CMD cmd = CMD(message);
    size_t pos = cmd.body.find("$");
    string str_size = cmd.body.substr(0, pos);
    string str_role = cmd.body.substr(pos + 1);
    role = atoi(str_role.c_str());
    your_turn = role == 1;
    int size = atoi(str_size.c_str());
    scene = new GameScene(size);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    pause_state = false;
    if(your_turn){
        ui->player_turn->setText("Your turn");
    }else {
        ui->player_turn->setText("Opponent's turn");
    }

    connect(this,&gamewindow::update_board, scene, &GameScene::update_board);
}

void gamewindow::handle_update_board_response(string message){
    emit update_board(message);
    if(your_turn){
        ui->player_turn->setText("Your turn");
    }else {
        ui->player_turn->setText("Opponent's turn");
    }
}

void gamewindow::handle_winner_response(string message){
    CMD response_cmd = CMD(message);
    size_t pos_1 = response_cmd.body.find("$");
    string move = response_cmd.body.substr(0,pos_1);
    string role_str = response_cmd.body.substr(pos_1+1);
    int winner = atoi(role_str.c_str());
    string win_message;
    if(winner!=role){
        win_message = "You lost!";
    }else{
        win_message = "You won!";
    }

    QMessageBox msg_box(QMessageBox::Information, "Match ended", win_message.c_str(), QMessageBox::NoButton, this);

    QPushButton *home_button = msg_box.addButton(tr("Home"), QMessageBox::AcceptRole);
    QPushButton *ok_button = msg_box.addButton(tr("OK"), QMessageBox::RejectRole);
    QPushButton *rematch_button = msg_box.addButton(tr("Rematch"), QMessageBox::ActionRole);
    pause_state = true;
    msg_box.setDefaultButton(ok_button);
    msg_box.exec();
    if (msg_box.clickedButton() == home_button) {
        stackedWidget->setCurrentIndex(2);
    } else if (msg_box.clickedButton() == ok_button) {

    }else {
        CMD cmd = CMD("CMD15",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }

    emit update_board(message);
}

void gamewindow::handle_rematch_response(string message){
    CMD response_cmd = CMD(message);
    QMessageBox msg_box(QMessageBox::Information, "Rematch ?", "Your opponent want a rematch", QMessageBox::NoButton, this);

    QPushButton *accept_btn = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
    QPushButton *decline_btn = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);
    msg_box.setDefaultButton(accept_btn);
    msg_box.exec();
    if (msg_box.clickedButton() == accept_btn) {
        CMD cmd = CMD("CMD16",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    } else if (msg_box.clickedButton() == decline_btn) {
        CMD cmd = CMD("CMD17",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}


void gamewindow::on_pause_clicked()
{
    if(!pause_state){
        pause_state = true;
        ui->pause->setText("continue");
        CMD cmd = CMD("CMD18",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }else{
        ui->pause->setText("Pause");
    }
}

void gamewindow::handle_pause_response(string message){
    CMD response_cmd = CMD(message);
    QMessageBox msg_box(QMessageBox::Information, "Pause", response_cmd.body.c_str(), QMessageBox::NoButton, this);

    QPushButton *accept_btn = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
    QPushButton *decline_btn = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);
    msg_box.setDefaultButton(accept_btn);
    msg_box.exec();
    if (msg_box.clickedButton() == accept_btn) {
        ui->pause->setText("continue");
        pause_state = true;
        CMD cmd = CMD("CMD19",token,"ACCEPT");
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    } else if (msg_box.clickedButton() == decline_btn) {
        string message = room_id;
        CMD cmd = CMD("CMD19",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}

void gamewindow::handle_pause_decline_response(string message){
    CMD response_cmd = CMD(message);
    QMessageBox::information(this, tr("Unpause"), tr(response_cmd.body.c_str()));
    pause_state = false;
    ui->pause->setText("Pause");
}
