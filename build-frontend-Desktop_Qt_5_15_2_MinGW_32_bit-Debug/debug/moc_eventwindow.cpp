/****************************************************************************
** Meta object code from reading C++ file 'eventwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend/eventwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventWindow_t {
    QByteArrayData data[21];
    char stringdata0[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventWindow_t qt_meta_stringdata_EventWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EventWindow"
QT_MOC_LITERAL(1, 12, 8), // "addEvent"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 37, 5), // "reply"
QT_MOC_LITERAL(5, 43, 11), // "checkInputB"
QT_MOC_LITERAL(6, 55, 17), // "on_eventB_clicked"
QT_MOC_LITERAL(7, 73, 18), // "on_withd20_clicked"
QT_MOC_LITERAL(8, 92, 18), // "on_withd40_clicked"
QT_MOC_LITERAL(9, 111, 18), // "on_withd50_clicked"
QT_MOC_LITERAL(10, 130, 19), // "on_withd100_clicked"
QT_MOC_LITERAL(11, 150, 23), // "on_inputPressed_clicked"
QT_MOC_LITERAL(12, 174, 11), // "createEvent"
QT_MOC_LITERAL(13, 186, 3), // "num"
QT_MOC_LITERAL(14, 190, 28), // "on_inputWith_editingFinished"
QT_MOC_LITERAL(15, 219, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(16, 243, 23), // "on_inputWith_textEdited"
QT_MOC_LITERAL(17, 267, 4), // "arg1"
QT_MOC_LITERAL(18, 272, 11), // "eventUpdate"
QT_MOC_LITERAL(19, 284, 5), // "input"
QT_MOC_LITERAL(20, 290, 8) // "TimerEnd"

    },
    "EventWindow\0addEvent\0\0QNetworkReply*\0"
    "reply\0checkInputB\0on_eventB_clicked\0"
    "on_withd20_clicked\0on_withd40_clicked\0"
    "on_withd50_clicked\0on_withd100_clicked\0"
    "on_inputPressed_clicked\0createEvent\0"
    "num\0on_inputWith_editingFinished\0"
    "on_pushButton_5_clicked\0on_inputWith_textEdited\0"
    "arg1\0eventUpdate\0input\0TimerEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    1,   96,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,

       0        // eod
};

void EventWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addEvent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->checkInputB((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->on_eventB_clicked(); break;
        case 3: _t->on_withd20_clicked(); break;
        case 4: _t->on_withd40_clicked(); break;
        case 5: _t->on_withd50_clicked(); break;
        case 6: _t->on_withd100_clicked(); break;
        case 7: _t->on_inputPressed_clicked(); break;
        case 8: _t->createEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_inputWith_editingFinished(); break;
        case 10: _t->on_pushButton_5_clicked(); break;
        case 11: _t->on_inputWith_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->eventUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->TimerEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EventWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EventWindow.data,
    qt_meta_data_EventWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EventWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EventWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
