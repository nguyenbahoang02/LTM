/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI/gamewindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSgamewindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSgamewindowENDCLASS = QtMocHelpers::stringData(
    "gamewindow",
    "update_board",
    "",
    "std::string",
    "handle_create_match_response",
    "handle_update_board_response",
    "handle_winner_response",
    "handle_rematch_response",
    "handle_pause_response",
    "handle_pause_accept_response",
    "handle_pause_decline_response",
    "handle_continue_response",
    "handle_continue_accept_response",
    "handle_continue_decline_response",
    "handle_draw_response",
    "handle_draw_accept_response",
    "handle_draw_decline_response",
    "handle_chat_response",
    "on_pause_clicked",
    "on_draw_clicked",
    "on_return_2_clicked",
    "on_send_clicked",
    "on_message_returnPressed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSgamewindowENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[29];
    char stringdata5[29];
    char stringdata6[23];
    char stringdata7[24];
    char stringdata8[22];
    char stringdata9[29];
    char stringdata10[30];
    char stringdata11[25];
    char stringdata12[32];
    char stringdata13[33];
    char stringdata14[21];
    char stringdata15[28];
    char stringdata16[29];
    char stringdata17[21];
    char stringdata18[17];
    char stringdata19[16];
    char stringdata20[20];
    char stringdata21[16];
    char stringdata22[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSgamewindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSgamewindowENDCLASS_t qt_meta_stringdata_CLASSgamewindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "gamewindow"
        QT_MOC_LITERAL(11, 12),  // "update_board"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 11),  // "std::string"
        QT_MOC_LITERAL(37, 28),  // "handle_create_match_response"
        QT_MOC_LITERAL(66, 28),  // "handle_update_board_response"
        QT_MOC_LITERAL(95, 22),  // "handle_winner_response"
        QT_MOC_LITERAL(118, 23),  // "handle_rematch_response"
        QT_MOC_LITERAL(142, 21),  // "handle_pause_response"
        QT_MOC_LITERAL(164, 28),  // "handle_pause_accept_response"
        QT_MOC_LITERAL(193, 29),  // "handle_pause_decline_response"
        QT_MOC_LITERAL(223, 24),  // "handle_continue_response"
        QT_MOC_LITERAL(248, 31),  // "handle_continue_accept_response"
        QT_MOC_LITERAL(280, 32),  // "handle_continue_decline_response"
        QT_MOC_LITERAL(313, 20),  // "handle_draw_response"
        QT_MOC_LITERAL(334, 27),  // "handle_draw_accept_response"
        QT_MOC_LITERAL(362, 28),  // "handle_draw_decline_response"
        QT_MOC_LITERAL(391, 20),  // "handle_chat_response"
        QT_MOC_LITERAL(412, 16),  // "on_pause_clicked"
        QT_MOC_LITERAL(429, 15),  // "on_draw_clicked"
        QT_MOC_LITERAL(445, 19),  // "on_return_2_clicked"
        QT_MOC_LITERAL(465, 15),  // "on_send_clicked"
        QT_MOC_LITERAL(481, 24)   // "on_message_returnPressed"
    },
    "gamewindow",
    "update_board",
    "",
    "std::string",
    "handle_create_match_response",
    "handle_update_board_response",
    "handle_winner_response",
    "handle_rematch_response",
    "handle_pause_response",
    "handle_pause_accept_response",
    "handle_pause_decline_response",
    "handle_continue_response",
    "handle_continue_accept_response",
    "handle_continue_decline_response",
    "handle_draw_response",
    "handle_draw_accept_response",
    "handle_draw_decline_response",
    "handle_chat_response",
    "on_pause_clicked",
    "on_draw_clicked",
    "on_return_2_clicked",
    "on_send_clicked",
    "on_message_returnPressed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSgamewindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,  137,    2, 0x0a,    3 /* Public */,
       5,    1,  140,    2, 0x0a,    5 /* Public */,
       6,    1,  143,    2, 0x0a,    7 /* Public */,
       7,    1,  146,    2, 0x0a,    9 /* Public */,
       8,    1,  149,    2, 0x0a,   11 /* Public */,
       9,    1,  152,    2, 0x0a,   13 /* Public */,
      10,    1,  155,    2, 0x0a,   15 /* Public */,
      11,    1,  158,    2, 0x0a,   17 /* Public */,
      12,    1,  161,    2, 0x0a,   19 /* Public */,
      13,    1,  164,    2, 0x0a,   21 /* Public */,
      14,    1,  167,    2, 0x0a,   23 /* Public */,
      15,    1,  170,    2, 0x0a,   25 /* Public */,
      16,    1,  173,    2, 0x0a,   27 /* Public */,
      17,    1,  176,    2, 0x0a,   29 /* Public */,
      18,    0,  179,    2, 0x08,   31 /* Private */,
      19,    0,  180,    2, 0x08,   32 /* Private */,
      20,    0,  181,    2, 0x08,   33 /* Private */,
      21,    0,  182,    2, 0x08,   34 /* Private */,
      22,    0,  183,    2, 0x08,   35 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject gamewindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSgamewindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSgamewindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSgamewindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<gamewindow, std::true_type>,
        // method 'update_board'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_create_match_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_update_board_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_winner_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_rematch_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_pause_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_pause_accept_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_pause_decline_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_continue_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_continue_accept_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_continue_decline_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_draw_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_draw_accept_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_draw_decline_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handle_chat_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'on_pause_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_draw_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_return_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_send_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_message_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void gamewindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<gamewindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->update_board((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->handle_create_match_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 2: _t->handle_update_board_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 3: _t->handle_winner_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 4: _t->handle_rematch_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->handle_pause_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 6: _t->handle_pause_accept_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 7: _t->handle_pause_decline_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 8: _t->handle_continue_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 9: _t->handle_continue_accept_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 10: _t->handle_continue_decline_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 11: _t->handle_draw_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 12: _t->handle_draw_accept_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 13: _t->handle_draw_decline_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 14: _t->handle_chat_response((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 15: _t->on_pause_clicked(); break;
        case 16: _t->on_draw_clicked(); break;
        case 17: _t->on_return_2_clicked(); break;
        case 18: _t->on_send_clicked(); break;
        case 19: _t->on_message_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (gamewindow::*)(std::string );
            if (_t _q_method = &gamewindow::update_board; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *gamewindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gamewindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSgamewindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int gamewindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void gamewindow::update_board(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
