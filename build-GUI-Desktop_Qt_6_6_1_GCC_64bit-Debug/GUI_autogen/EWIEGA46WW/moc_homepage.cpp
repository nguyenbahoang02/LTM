/****************************************************************************
** Meta object code from reading C++ file 'homepage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI/homepage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homepage.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSHomePageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSHomePageENDCLASS = QtMocHelpers::stringData(
    "HomePage",
    "handle_logout_response",
    "",
    "std::string",
    "message",
    "handle_find_match_response",
    "handle_player_list_response",
    "handle_received_challenge",
    "handle_declined_challenge_response",
    "handle_created_room_response",
    "handle_accept_find_match_response",
    "on_log_out_btn_clicked",
    "on_find_match_btn_clicked",
    "on_get_online_players_clicked",
    "send_challenge",
    "username"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHomePageENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[9];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[27];
    char stringdata6[28];
    char stringdata7[26];
    char stringdata8[35];
    char stringdata9[29];
    char stringdata10[34];
    char stringdata11[23];
    char stringdata12[26];
    char stringdata13[30];
    char stringdata14[15];
    char stringdata15[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHomePageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHomePageENDCLASS_t qt_meta_stringdata_CLASSHomePageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "HomePage"
        QT_MOC_LITERAL(9, 22),  // "handle_logout_response"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 11),  // "std::string"
        QT_MOC_LITERAL(45, 7),  // "message"
        QT_MOC_LITERAL(53, 26),  // "handle_find_match_response"
        QT_MOC_LITERAL(80, 27),  // "handle_player_list_response"
        QT_MOC_LITERAL(108, 25),  // "handle_received_challenge"
        QT_MOC_LITERAL(134, 34),  // "handle_declined_challenge_res..."
        QT_MOC_LITERAL(169, 28),  // "handle_created_room_response"
        QT_MOC_LITERAL(198, 33),  // "handle_accept_find_match_resp..."
        QT_MOC_LITERAL(232, 22),  // "on_log_out_btn_clicked"
        QT_MOC_LITERAL(255, 25),  // "on_find_match_btn_clicked"
        QT_MOC_LITERAL(281, 29),  // "on_get_online_players_clicked"
        QT_MOC_LITERAL(311, 14),  // "send_challenge"
        QT_MOC_LITERAL(326, 8)   // "username"
    },
    "HomePage",
    "handle_logout_response",
    "",
    "std::string",
    "message",
    "handle_find_match_response",
    "handle_player_list_response",
    "handle_received_challenge",
    "handle_declined_challenge_response",
    "handle_created_room_response",
    "handle_accept_find_match_response",
    "on_log_out_btn_clicked",
    "on_find_match_btn_clicked",
    "on_get_online_players_clicked",
    "send_challenge",
    "username"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHomePageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x0a,    1 /* Public */,
       5,    1,   83,    2, 0x0a,    3 /* Public */,
       6,    1,   86,    2, 0x0a,    5 /* Public */,
       7,    1,   89,    2, 0x0a,    7 /* Public */,
       8,    1,   92,    2, 0x0a,    9 /* Public */,
       9,    1,   95,    2, 0x0a,   11 /* Public */,
      10,    1,   98,    2, 0x0a,   13 /* Public */,
      11,    0,  101,    2, 0x08,   15 /* Private */,
      12,    0,  102,    2, 0x08,   16 /* Private */,
      13,    0,  103,    2, 0x08,   17 /* Private */,
      14,    1,  104,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject HomePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSHomePageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHomePageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHomePageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HomePage, std::true_type>,
        // method 'handle_logout_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_find_match_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_player_list_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_received_challenge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_declined_challenge_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_created_room_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_accept_find_match_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'on_log_out_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_find_match_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_get_online_players_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_challenge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>
    >,
    nullptr
} };

void HomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HomePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handle_logout_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->handle_find_match_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 2: _t->handle_player_list_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 3: _t->handle_received_challenge((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 4: _t->handle_declined_challenge_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->handle_created_room_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 6: _t->handle_accept_find_match_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 7: _t->on_log_out_btn_clicked(); break;
        case 8: _t->on_find_match_btn_clicked(); break;
        case 9: _t->on_get_online_players_clicked(); break;
        case 10: _t->send_challenge((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *HomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHomePageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
