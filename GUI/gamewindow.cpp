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
bool wait_for_response;
bool game_over;

gamewindow::gamewindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    connect(ui->pause, &QPushButton::clicked,
            this, &gamewindow::on_pause_clicked);
    connect(ui->draw, &QPushButton::clicked,
            this, &gamewindow::on_draw_clicked);
    connect(ui->return_2,&QPushButton::clicked,
            this,&gamewindow::on_return_2_clicked);

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
    wait_for_response = false;
    game_over = false;
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

    QWidget *scrollContent = ui->scrollAreaWidgetContents;
    scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    vbox = scrollLayout;

    QScrollArea *scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);

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
    game_over = true;
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
    if(!pause_state&&!wait_for_response){
        pause_state = true;
        wait_for_response = true;
        ui->pause->setText("Continue");
        CMD cmd = CMD("CMD18",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
        return;
    }else if(pause_state&&!wait_for_response){
        CMD cmd = CMD("CMD21",token,room_id);
        wait_for_response = true;
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
        ui->pause->setText("Pause");
        return;
    }
}

void gamewindow::handle_pause_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    QMessageBox msg_box(QMessageBox::Information, "Pause", response_cmd.body.c_str(), QMessageBox::NoButton, this);

    QPushButton *accept_btn = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
    QPushButton *decline_btn = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);
    msg_box.setDefaultButton(accept_btn);
    msg_box.exec();
    if (msg_box.clickedButton() == accept_btn) {
        ui->pause->setText("Continue");
        pause_state = true;
        CMD cmd = CMD("CMD19",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    } else if (msg_box.clickedButton() == decline_btn) {
        string message = room_id;
        CMD cmd = CMD("CMD20",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}

void gamewindow::handle_pause_accept_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
}

void gamewindow::handle_pause_decline_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    QMessageBox::information(this, tr("Unpause"), tr(response_cmd.body.c_str()));
    pause_state = false;
    ui->pause->setText("Pause");
}

void gamewindow::handle_continue_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    QMessageBox msg_box(QMessageBox::Information, "Continue", response_cmd.body.c_str(), QMessageBox::NoButton, this);

    QPushButton *accept_btn = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
    QPushButton *decline_btn = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);
    msg_box.setDefaultButton(accept_btn);
    msg_box.exec();
    if (msg_box.clickedButton() == accept_btn) {
        ui->pause->setText("Pause");
        pause_state = false;
        CMD cmd = CMD("CMD22",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    } else if (msg_box.clickedButton() == decline_btn) {
        string message = room_id;
        CMD cmd = CMD("CMD23",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}

void gamewindow::handle_continue_decline_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    QMessageBox::information(this, tr("Pause"), tr(response_cmd.body.c_str()));
}

void gamewindow::handle_continue_accept_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    ui->pause->setText("Pause");
    pause_state = false;
    QMessageBox::information(this, tr("Pause"), tr("Game continue"));
}

void gamewindow::on_draw_clicked()
{
    if(!wait_for_response){
        wait_for_response = true;
        CMD cmd = CMD("CMD24",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}

void gamewindow::handle_draw_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    QMessageBox msg_box(QMessageBox::Information, "Draw", response_cmd.body.c_str(), QMessageBox::NoButton, this);

    QPushButton *accept_btn = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
    QPushButton *decline_btn = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);
    msg_box.setDefaultButton(accept_btn);
    msg_box.exec();
    if (msg_box.clickedButton() == accept_btn) {
        pause_state = true;
        game_over = true;
        CMD cmd = CMD("CMD25",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    } else if (msg_box.clickedButton() == decline_btn) {
        string message = room_id;
        CMD cmd = CMD("CMD26",token,room_id);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}

void gamewindow::handle_draw_decline_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    QMessageBox::information(this, tr("Pause"), tr(response_cmd.body.c_str()));
}

void gamewindow::handle_draw_accept_response(string message){
    CMD response_cmd = CMD(message);
    wait_for_response = false;
    pause_state = true;
    game_over = true;
    QMessageBox::information(this, tr("Draw"), tr("Game over"));
}

void gamewindow::on_return_2_clicked()
{
    if(game_over){
        stackedWidget->setCurrentIndex(2);
    }else{
        QMessageBox::information(this, tr("Can't"), tr("Can't return while match is going"));
    }
}


void gamewindow::on_send_clicked()
{
    if(ui->message->text().toStdString()!=""){
        string message = room_id;
        message.append("*");
        message.append(ui->message->text().toStdString());
        CMD cmd = CMD("CMD27",token,message);
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    }
}

void gamewindow::handle_chat_response(string message){
    CMD response_cmd = CMD(message);
    size_t pos = response_cmd.body.find("*");
    string username = response_cmd.body.substr(0, pos);
    string chat = response_cmd.body.substr(pos + 1);

    string chat_message = username;
    chat_message.append(": ");
    chat_message.append(chat);

    QLabel *item_name = new QLabel(chat_message.c_str());

    vbox->addWidget(item_name);
}
