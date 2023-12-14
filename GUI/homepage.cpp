#include "homepage.h"
#include "ui_homepage.h"
#include "../cmd.h"

using namespace std;

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_save_btn_clicked()
{
    ::send(server_sock,"123",3,0);
}

