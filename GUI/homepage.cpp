#include "homepage.h"
#include "ui_homepage.h"
#include "../cmd.h"
#include "token.h"
#include <QMessageBox>

#define BUFF_SIZE 1024

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

void HomePage::on_log_out_btn_clicked()
{
    char buff[BUFF_SIZE];
    int bytes_received;
    CMD cmd = CMD("CMD03",token);
    ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    stackedWidget->setCurrentIndex(0);
    bytes_received = recv(server_sock, buff, BUFF_SIZE - 1, 0);
    if (bytes_received < 0)
    {
        perror("Error: ");
        ::close(server_sock);
        return ;
    }
    CMD response_cmd = CMD(buff);
    stackedWidget->setCurrentIndex(0);
    QMessageBox::information(this, tr("LOGOUT"), tr("Logout successfully."));
}


void HomePage::on_find_match_btn_clicked()
{
    char buff[BUFF_SIZE];
    int bytes_received;
    CMD cmd = CMD("CMD05",token);
    ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
    bytes_received = recv(server_sock, buff, BUFF_SIZE - 1, 0);
    if (bytes_received < 0)
    {
        perror("Error: ");
        ::close(server_sock);
        return ;
    }
    CMD response_cmd = CMD(buff);
    cout << response_cmd.cmd << endl;
}

