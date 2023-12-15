#include "signin.h"
#include "ui_signin.h"
#include "../cmd.h"
#include <QMessageBox>
#include "token.h"

using namespace std;

#define BUFF_SIZE 1024

char buff[BUFF_SIZE];
int bytes_sent, bytes_received;
string token = "";
SignIn::SignIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    ::close(server_sock);
    delete ui;
}

void SignIn::on_sign_up_clicked()
{
    stackedWidget->setCurrentIndex(1);
}


void SignIn::on_sign_in_clicked()
{
    string username =  ui->username_text->text().toStdString();
    string password = ui->password_text->text().toStdString();
    if(username==""||password==""){
        QMessageBox::critical(this,tr("LOGIN"),tr("PLEASE FILL IN ALL REQUIRED FIELDS"));
        return;
    }
    string body = "";
    body.append(username).append("#").append(password);
    CMD cmd = CMD("CMD01",body);
    ::send(server_sock, cmd.cmd,  strlen(cmd.cmd), 0);
    memset(buff, '\0', (strlen(buff) + 1));
    bytes_received = recv(server_sock, buff, BUFF_SIZE - 1, 0);
    if (bytes_received < 0)
    {
        perror("Error: ");
        ::close(server_sock);
        return ;
    }
    CMD response_cmd = CMD(buff);
    if(response_cmd.body=="LOGIN_SUCCESSFULLY"){ 
        token = response_cmd.token;
        stackedWidget->setCurrentIndex(2);
        QMessageBox::information(this, tr("LOGIN"), tr("Login successfully."));
    }else{
        QMessageBox::critical(this,tr("LOGIN"),tr(response_cmd.body.c_str()));
    }


}

