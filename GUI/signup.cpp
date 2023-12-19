#include "signup.h"
#include "ui_signup.h"
#include "token.h"
#include <QMessageBox>
#include "../cmd.h"

#define BUFF_SIZE 1024

using namespace std;

SignUp::SignUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_sign_in_btn_clicked()
{
    stackedWidget->setCurrentIndex(0);
}


void SignUp::on_sign_up_clicked()
{
    char buff[BUFF_SIZE];
    int bytes_received;
    string username =  ui->username_text->text().toStdString();
    string password = ui->password_text->text().toStdString();
    if(username==""||password==""){
        QMessageBox::critical(this,tr("SIGN UP"),tr("PLEASE FILL IN ALL REQUIRED FIELDS"));
        return;
    }
    string body = "";
    body.append(username).append("#").append(password);
    CMD cmd = CMD("CMD02",body);
    ::send(server_sock, cmd.cmd,  strlen(cmd.cmd), 0);
}

void SignUp::handle_response(string message){
    CMD response_cmd = CMD(message);
    if(response_cmd.body!="USERNAME_EXISTS"){
        QMessageBox::information(this, tr("SIGN UP"), tr("Sign up successfully."));
    }else{
        QMessageBox::critical(this,tr("SIGN UP"),tr(response_cmd.body.c_str()));
    }
}

