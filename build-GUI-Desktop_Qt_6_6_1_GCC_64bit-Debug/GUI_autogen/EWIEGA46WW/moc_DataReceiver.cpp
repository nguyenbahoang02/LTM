/****************************************************************************
** Meta object code from reading C++ file 'DataReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI/DataReceiver.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDataReceiverENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDataReceiverENDCLASS = QtMocHelpers::stringData(
    "DataReceiver",
    "login_response_signal",
    "",
    "std::string",
    "message",
    "signup_response_signal",
    "logout_response_signal",
    "find_match_response_signal",
    "player_list_signal",
    "received_challenge_signal",
    "declined_challenge_signal",
    "created_room_signal",
    "accept_find_match_signal",
    "create_board_signal",
    "update_board_signal",
    "winner_signal",
    "rematch_signal",
    "re_login_response_signal",
    "pause_signal",
    "pause_accept_signal",
    "pause_decline_signal",
    "continue_signal",
    "continue_accept_signal",
    "continue_decline_signal",
    "draw_signal",
    "draw_accept_signal",
    "draw_decline_signal",
    "chat_signal",
    "GetSignal"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDataReceiverENDCLASS_t {
    uint offsetsAndSizes[58];
    char stringdata0[13];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[23];
    char stringdata6[23];
    char stringdata7[27];
    char stringdata8[19];
    char stringdata9[26];
    char stringdata10[26];
    char stringdata11[20];
    char stringdata12[25];
    char stringdata13[20];
    char stringdata14[20];
    char stringdata15[14];
    char stringdata16[15];
    char stringdata17[25];
    char stringdata18[13];
    char stringdata19[20];
    char stringdata20[21];
    char stringdata21[16];
    char stringdata22[23];
    char stringdata23[24];
    char stringdata24[12];
    char stringdata25[19];
    char stringdata26[20];
    char stringdata27[12];
    char stringdata28[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDataReceiverENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDataReceiverENDCLASS_t qt_meta_stringdata_CLASSDataReceiverENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "DataReceiver"
        QT_MOC_LITERAL(13, 21),  // "login_response_signal"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "std::string"
        QT_MOC_LITERAL(48, 7),  // "message"
        QT_MOC_LITERAL(56, 22),  // "signup_response_signal"
        QT_MOC_LITERAL(79, 22),  // "logout_response_signal"
        QT_MOC_LITERAL(102, 26),  // "find_match_response_signal"
        QT_MOC_LITERAL(129, 18),  // "player_list_signal"
        QT_MOC_LITERAL(148, 25),  // "received_challenge_signal"
        QT_MOC_LITERAL(174, 25),  // "declined_challenge_signal"
        QT_MOC_LITERAL(200, 19),  // "created_room_signal"
        QT_MOC_LITERAL(220, 24),  // "accept_find_match_signal"
        QT_MOC_LITERAL(245, 19),  // "create_board_signal"
        QT_MOC_LITERAL(265, 19),  // "update_board_signal"
        QT_MOC_LITERAL(285, 13),  // "winner_signal"
        QT_MOC_LITERAL(299, 14),  // "rematch_signal"
        QT_MOC_LITERAL(314, 24),  // "re_login_response_signal"
        QT_MOC_LITERAL(339, 12),  // "pause_signal"
        QT_MOC_LITERAL(352, 19),  // "pause_accept_signal"
        QT_MOC_LITERAL(372, 20),  // "pause_decline_signal"
        QT_MOC_LITERAL(393, 15),  // "continue_signal"
        QT_MOC_LITERAL(409, 22),  // "continue_accept_signal"
        QT_MOC_LITERAL(432, 23),  // "continue_decline_signal"
        QT_MOC_LITERAL(456, 11),  // "draw_signal"
        QT_MOC_LITERAL(468, 18),  // "draw_accept_signal"
        QT_MOC_LITERAL(487, 19),  // "draw_decline_signal"
        QT_MOC_LITERAL(507, 11),  // "chat_signal"
        QT_MOC_LITERAL(519, 9)   // "GetSignal"
    },
    "DataReceiver",
    "login_response_signal",
    "",
    "std::string",
    "message",
    "signup_response_signal",
    "logout_response_signal",
    "find_match_response_signal",
    "player_list_signal",
    "received_challenge_signal",
    "declined_challenge_signal",
    "created_room_signal",
    "accept_find_match_signal",
    "create_board_signal",
    "update_board_signal",
    "winner_signal",
    "rematch_signal",
    "re_login_response_signal",
    "pause_signal",
    "pause_accept_signal",
    "pause_decline_signal",
    "continue_signal",
    "continue_accept_signal",
    "continue_decline_signal",
    "draw_signal",
    "draw_accept_signal",
    "draw_decline_signal",
    "chat_signal",
    "GetSignal"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDataReceiverENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  164,    2, 0x06,    1 /* Public */,
       5,    1,  167,    2, 0x06,    3 /* Public */,
       6,    1,  170,    2, 0x06,    5 /* Public */,
       7,    1,  173,    2, 0x06,    7 /* Public */,
       8,    1,  176,    2, 0x06,    9 /* Public */,
       9,    1,  179,    2, 0x06,   11 /* Public */,
      10,    1,  182,    2, 0x06,   13 /* Public */,
      11,    1,  185,    2, 0x06,   15 /* Public */,
      12,    1,  188,    2, 0x06,   17 /* Public */,
      13,    1,  191,    2, 0x06,   19 /* Public */,
      14,    1,  194,    2, 0x06,   21 /* Public */,
      15,    1,  197,    2, 0x06,   23 /* Public */,
      16,    1,  200,    2, 0x06,   25 /* Public */,
      17,    1,  203,    2, 0x06,   27 /* Public */,
      18,    1,  206,    2, 0x06,   29 /* Public */,
      19,    1,  209,    2, 0x06,   31 /* Public */,
      20,    1,  212,    2, 0x06,   33 /* Public */,
      21,    1,  215,    2, 0x06,   35 /* Public */,
      22,    1,  218,    2, 0x06,   37 /* Public */,
      23,    1,  221,    2, 0x06,   39 /* Public */,
      24,    1,  224,    2, 0x06,   41 /* Public */,
      25,    1,  227,    2, 0x06,   43 /* Public */,
      26,    1,  230,    2, 0x06,   45 /* Public */,
      27,    1,  233,    2, 0x06,   47 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      28,    0,  236,    2, 0x0a,   49 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DataReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDataReceiverENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDataReceiverENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDataReceiverENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DataReceiver, std::true_type>,
        // method 'login_response_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'signup_response_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'logout_response_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'find_match_response_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'player_list_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'received_challenge_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'declined_challenge_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'created_room_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'accept_find_match_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'create_board_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'update_board_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'winner_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'rematch_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 're_login_response_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'pause_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'pause_accept_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'pause_decline_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'continue_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'continue_accept_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'continue_decline_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'draw_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'draw_accept_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'draw_decline_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'chat_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'GetSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DataReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->login_response_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->signup_response_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 2: _t->logout_response_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 3: _t->find_match_response_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 4: _t->player_list_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->received_challenge_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 6: _t->declined_challenge_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 7: _t->created_room_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 8: _t->accept_find_match_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 9: _t->create_board_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 10: _t->update_board_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 11: _t->winner_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 12: _t->rematch_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 13: _t->re_login_response_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 14: _t->pause_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 15: _t->pause_accept_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 16: _t->pause_decline_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 17: _t->continue_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 18: _t->continue_accept_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 19: _t->continue_decline_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 20: _t->draw_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 21: _t->draw_accept_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 22: _t->draw_decline_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 23: _t->chat_signal((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 24: _t->GetSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::login_response_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::signup_response_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::logout_response_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::find_match_response_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::player_list_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::received_challenge_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::declined_challenge_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::created_room_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::accept_find_match_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::create_board_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::update_board_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::winner_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::rematch_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::re_login_response_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::pause_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::pause_accept_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::pause_decline_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::continue_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::continue_accept_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::continue_decline_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::draw_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::draw_accept_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::draw_decline_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (DataReceiver::*)(std::string );
            if (_t _q_method = &DataReceiver::chat_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
    }
}

const QMetaObject *DataReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDataReceiverENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void DataReceiver::login_response_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataReceiver::signup_response_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataReceiver::logout_response_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataReceiver::find_match_response_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataReceiver::player_list_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataReceiver::received_challenge_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataReceiver::declined_challenge_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DataReceiver::created_room_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DataReceiver::accept_find_match_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DataReceiver::create_board_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void DataReceiver::update_board_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void DataReceiver::winner_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void DataReceiver::rematch_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void DataReceiver::re_login_response_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void DataReceiver::pause_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void DataReceiver::pause_accept_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void DataReceiver::pause_decline_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void DataReceiver::continue_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void DataReceiver::continue_accept_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void DataReceiver::continue_decline_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void DataReceiver::draw_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void DataReceiver::draw_accept_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void DataReceiver::draw_decline_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void DataReceiver::chat_signal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}
QT_WARNING_POP
