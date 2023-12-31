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
}

void SignIn::handle_response(string message){
    CMD response_cmd = CMD(message);
    if(response_cmd.body=="LOGIN_SUCCESSFULLY"){
        token = response_cmd.token;
        stackedWidget->setCurrentIndex(2);
        QMessageBox::information(this, tr("LOGIN"), tr("Login successfully."));
    }else{
        QMessageBox::critical(this,tr("LOGIN"),tr(response_cmd.body.c_str()));
    }
}

void SignIn::handle_re_login_response(string message){
    stackedWidget->setCurrentIndex(0);
    QMessageBox::information(this,tr("Relogin"),tr("Your session has ended please relogin"));
}
