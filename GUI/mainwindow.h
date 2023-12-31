#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signup.h"
#include "signin.h"
#include "homepage.h"
#include "DataReceiver.h"
#include "gamewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char *argv[]);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SignUp sign_up;
    SignIn sign_in;
    HomePage home_page;
    DataReceiver *data_receiver;
    gamewindow game_window;
    QThread *thread;
};
#endif // MAINWINDOW_H
