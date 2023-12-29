#include "homepage.h"
#include "ui_homepage.h"
#include "../cmd.h"
#include "token.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGroupBox>

#define BUFF_SIZE 1024

using namespace std;

string room_id="";

HomePage::HomePage(QWidget *parent)
    : QWidget(parent), ui(new Ui::HomePage)
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
    CMD cmd = CMD("CMD03", token);
    ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
    stackedWidget->setCurrentIndex(0);
}

void HomePage::change_find_btn_state(){
    if (!finding_match)
    {
        finding_match = !finding_match;
        ui->find_match_btn->setText("Finding match");
    }
    else
    {
        finding_match = !finding_match;
        ui->find_match_btn->setText("Find a match");
    }
}

void HomePage::on_find_match_btn_clicked()
{
    if (!finding_match)
    {
        CMD cmd = CMD("CMD06", token, "1");
        ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
    }
    else
    {
        CMD cmd = CMD("CMD07", token, "1");
        ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
    }
    change_find_btn_state();
}

void HomePage::handle_logout_response(string message)
{
    CMD response_cmd = CMD(message);
    stackedWidget->setCurrentIndex(0);
    QMessageBox::information(this, tr("LOGOUT"), tr("Logout successfully."));
}

void HomePage::handle_find_match_response(string message)
{
    CMD response_cmd = CMD(message);
    room_id = response_cmd.token;
    if (response_cmd.body[0] == '0')
    {
        QMessageBox::critical(this, tr("LOGOUT"), tr("YOU NEED TO RELOGIN"));
        stackedWidget->setCurrentIndex(0);
    }
    else
    {
        QMessageBox msg_box(QMessageBox::Question, "FOUND A MATCH", "Found a match, accept ?", QMessageBox::NoButton, this);

        QPushButton *accept_button = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
        QPushButton *decline_button = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);

        msg_box.setDefaultButton(accept_button);
        msg_box.exec();
        string status = room_id;
        string room_accept_status = room_id;
        if (msg_box.clickedButton() == accept_button) {
            CMD cmd = CMD("CMD11", token, room_accept_status.append("%ACCEPT"));
            ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
        } else if (msg_box.clickedButton() == decline_button) {
            CMD cmd = CMD("CMD11", token, room_accept_status.append("%DECLINE"));
            ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
        }
        change_find_btn_state();
    }
}

list<string> extract_string_list(const std::string &input)
{
    list<string> result;
    stringstream ss(input);
    string item;
    while (getline(ss, item, '$'))
    {
        result.push_back(item);
    }
    result.pop_back();
    return result;
}

void HomePage::handle_player_list_response(string message)
{
    CMD response_cmd = CMD(message);
    list<string> online_players = extract_string_list(response_cmd.body.append("padding"));
    QWidget *scrollContent = ui->scrollAreaWidgetContents;
    scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    for (string s : online_players)
    {
        QGroupBox *item = new QGroupBox();
        QHBoxLayout *groupBoxLayout = new QHBoxLayout(item);

        QLabel *item_name = new QLabel(s.c_str());
        groupBoxLayout->addWidget(item_name);

        QPushButton *item_btn_challenge = new QPushButton("Send challenge");
        connect(item_btn_challenge, &QPushButton::clicked, [=]()
                { send_challenge(s); });
        groupBoxLayout->addWidget(item_btn_challenge, 0, Qt::AlignRight);
        scrollLayout->addWidget(item);
    }
    QScrollArea *scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}

void HomePage::on_get_online_players_clicked()
{
    CMD cmd = CMD("CMD05", token, "1");
    ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
}

void HomePage::send_challenge(string username)
{
    CMD cmd = CMD("CMD08", token, username);
    ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
}

void HomePage::handle_received_challenge(string message)
{
    CMD response_cmd = CMD(message);
    char buff[BUFF_SIZE];
    strcpy(buff,response_cmd.body.c_str());
    strcat(buff," challenge you to a match");

    QMessageBox msg_box(QMessageBox::Question, "CHALLENGE", buff, QMessageBox::NoButton, this);

    QPushButton *accept_button = msg_box.addButton(tr("Accept"), QMessageBox::AcceptRole);
    QPushButton *decline_button = msg_box.addButton(tr("Decline"), QMessageBox::RejectRole);

    msg_box.setDefaultButton(accept_button);
    msg_box.exec();

    if (msg_box.clickedButton() == accept_button) {
        CMD cmd = CMD("CMD09", token, response_cmd.body);
        ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
    } else if (msg_box.clickedButton() == decline_button) {
        CMD cmd = CMD("CMD10", token, response_cmd.body);
        ::send(server_sock, cmd.cmd, strlen(cmd.cmd), 0);
    }
}

void HomePage::handle_declined_challenge_response(string message){
    CMD response_cmd = CMD(message);
    char buff[BUFF_SIZE];
    strcpy(buff,response_cmd.body.c_str());
    QMessageBox::information(this, tr("DECLINED"), tr(buff));
}

void HomePage::handle_created_room_response(string message){
    CMD response_cmd = CMD(message);
    room_id = response_cmd.token;
    stackedWidget->setCurrentIndex(3);
}

void HomePage::handle_accept_find_match_response(string message){
    CMD response_cmd = CMD(message);
    if(response_cmd.body!="0"){
        stackedWidget->setCurrentIndex(3);
    }else{
        char buff[BUFF_SIZE];
        strcpy(buff,response_cmd.body.c_str());
        strcat(buff," has declined the match");
        QMessageBox::information(this, tr("DECLINED"), tr(buff));
    }
}
