/****************************************************************************
** Meta object code from reading C++ file 'deposidcahs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend/deposidcahs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deposidcahs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeposidCahs_t {
    QByteArrayData data[13];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeposidCahs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeposidCahs_t qt_meta_stringdata_DeposidCahs = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DeposidCahs"
QT_MOC_LITERAL(1, 12, 8), // "addEvent"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 37, 5), // "reply"
QT_MOC_LITERAL(5, 43, 18), // "on_withd20_clicked"
QT_MOC_LITERAL(6, 62, 18), // "on_withd40_clicked"
QT_MOC_LITERAL(7, 81, 18), // "on_withd50_clicked"
QT_MOC_LITERAL(8, 100, 19), // "on_withd100_clicked"
QT_MOC_LITERAL(9, 120, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(10, 144, 28), // "on_inputWith_editingFinished"
QT_MOC_LITERAL(11, 173, 23), // "on_inputPressed_clicked"
QT_MOC_LITERAL(12, 197, 8) // "TimerEnd"

    },
    "DeposidCahs\0addEvent\0\0QNetworkReply*\0"
    "reply\0on_withd20_clicked\0on_withd40_clicked\0"
    "on_withd50_clicked\0on_withd100_clicked\0"
    "on_pushButton_5_clicked\0"
    "on_inputWith_editingFinished\0"
    "on_inputPressed_clicked\0TimerEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeposidCahs[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeposidCahs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeposidCahs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addEvent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->on_withd20_clicked(); break;
        case 2: _t->on_withd40_clicked(); break;
        case 3: _t->on_withd50_clicked(); break;
        case 4: _t->on_withd100_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->on_inputWith_editingFinished(); break;
        case 7: _t->on_inputPressed_clicked(); break;
        case 8: _t->TimerEnd(); break;
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
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeposidCahs::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DeposidCahs.data,
    qt_meta_data_DeposidCahs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeposidCahs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeposidCahs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeposidCahs.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DeposidCahs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
