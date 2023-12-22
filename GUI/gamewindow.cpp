#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "../cmd.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "customrect.h"
#include <QDebug>
#include "token.h"
#include "gamescene.h"

using namespace std;

int role;
bool your_turn;

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
    connect(this,&gamewindow::update_board, scene, &GameScene::update_board);
}

void gamewindow::handle_update_board_response(string message){
    emit update_board(message);
}
