#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../cmd.h"
#include "token.h"
#include "homepage.h"
#define BUFF_SIZE 1024
int SERV_PORT;
char SERV_IP[100];
int server_sock;
struct sockaddr_in server_addr;
QStackedWidget *stackedWidget;
using namespace std;

MainWindow::MainWindow(int argc, char *argv[])
    : QMainWindow(), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(0,&sign_in);
    ui->stackedWidget->insertWidget(1,&sign_up);
    ui->stackedWidget->insertWidget(2,&home_page);
    ui->stackedWidget->setCurrentIndex(0);
    SERV_PORT = atoi(argv[2]);
    strcpy(SERV_IP, argv[1]);
    ::server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERV_IP);
    if (::connect(::server_sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
    {

    }
    stackedWidget = ui->stackedWidget;
    server_sock = ::server_sock;

}

MainWindow::~MainWindow()
{
    ::close(server_sock);
    delete ui;
}


