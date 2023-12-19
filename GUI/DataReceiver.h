#ifndef DATARECEIVER_H
#define DATARECEIVER_H
#include <QObject>
class DataReceiver : public QObject {
    Q_OBJECT

public:
    DataReceiver();

public slots:
    void GetSignal();

signals:
    void login_response_signal(std::string message);
    void signup_response_signal(std::string message);
    void logout_response_signal(std::string message);
    void find_match_response_signal(std::string message);
    void player_list_signal(std::string message);
};

#endif // DATARECEIVER_H


