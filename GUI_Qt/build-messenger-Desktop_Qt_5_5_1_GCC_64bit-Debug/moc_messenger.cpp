/****************************************************************************
** Meta object code from reading C++ file 'messenger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../messenger/messenger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messenger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Messenger_t {
    QByteArrayData data[8];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Messenger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Messenger_t qt_meta_stringdata_Messenger = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Messenger"
QT_MOC_LITERAL(1, 10, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 29), // "on_channelsListWidget_clicked"
QT_MOC_LITERAL(4, 63, 5), // "index"
QT_MOC_LITERAL(5, 69, 30), // "on_actionChange_Name_triggered"
QT_MOC_LITERAL(6, 100, 31), // "on_actionJoin_Channel_triggered"
QT_MOC_LITERAL(7, 132, 33) // "on_actionCreate_Channel_trigg..."

    },
    "Messenger\0on_sendButton_clicked\0\0"
    "on_channelsListWidget_clicked\0index\0"
    "on_actionChange_Name_triggered\0"
    "on_actionJoin_Channel_triggered\0"
    "on_actionCreate_Channel_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Messenger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Messenger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Messenger *_t = static_cast<Messenger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sendButton_clicked(); break;
        case 1: _t->on_channelsListWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_actionChange_Name_triggered(); break;
        case 3: _t->on_actionJoin_Channel_triggered(); break;
        case 4: _t->on_actionCreate_Channel_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject Messenger::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Messenger.data,
      qt_meta_data_Messenger,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Messenger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Messenger::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Messenger.stringdata0))
        return static_cast<void*>(const_cast< Messenger*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Messenger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
