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
    void received_challenge_signal(std::string message);
    void declined_challenge_signal(std::string message);
    void created_room_signal(std::string message);
    void accept_find_match_signal(std::string message);
    void create_board_signal(std::string message);
    void update_board_signal(std::string message);
};

#endif // DATARECEIVER_H



