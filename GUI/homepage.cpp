#include "homepage.h"
#include "ui_homepage.h"
#include "../cmd.h"
#include "token.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGroupBox>

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
}


void HomePage::on_find_match_btn_clicked()
{
    char buff[BUFF_SIZE];
    int bytes_received;
    if(!finding_match){
        CMD cmd = CMD("CMD06",token,"1");
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
        finding_match = !finding_match;
        ui->find_match_btn->setText("Finding match");
    }else{
        CMD cmd = CMD("CMD07",token,"1");
        ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
        finding_match = !finding_match;
        ui->find_match_btn->setText("Find a match");
    }
}

void HomePage::handle_logout_response(string message){
    CMD response_cmd = CMD(message);
    stackedWidget->setCurrentIndex(0);
    QMessageBox::information(this, tr("LOGOUT"), tr("Logout successfully."));
}

void HomePage::handle_find_match_response(string message){
    CMD response_cmd = CMD(message);
    if(response_cmd.body[0]=='0'){
        QMessageBox::critical(this, tr("LOGOUT"), tr("YOU NEED TO RELOGIN"));
        stackedWidget->setCurrentIndex(0);
    }else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "FOUND A MATCH", "Found a match, Accept?",
                                      QMessageBox::No|QMessageBox::Yes);
        if (reply == QMessageBox::Yes) {

        } else {
        }
    }

}

list<string> extractStringList(const std::string& input) {
    list<string> result;
    stringstream ss(input);
    string item;

    while (getline(ss, item, '$')) {
        result.push_back(item);
    }
    result.pop_back();
    return result;
}

void HomePage::handle_player_list_response(string message){
    CMD response_cmd = CMD(message);
    cout << response_cmd.body << endl;
    list<string> online_players = extractStringList(response_cmd.body);
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    for (string s : online_players) {
        QGroupBox* item= new QGroupBox();
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
        // Add text label to each group box
        QLabel* item_name = new QLabel(s.c_str());
        groupBoxLayout->addWidget(item_name);
        // Add button to join room
        QPushButton* item_btn_join = new QPushButton("Send challenge");
        groupBoxLayout->addWidget(item_btn_join,0, Qt::AlignRight);
        scrollLayout->addWidget(item);
    }
    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);


}

void HomePage::on_get_online_players_clicked()
{
    CMD cmd = CMD("CMD05",token,"1");
    ::send(server_sock,cmd.cmd,strlen(cmd.cmd),0);
}

