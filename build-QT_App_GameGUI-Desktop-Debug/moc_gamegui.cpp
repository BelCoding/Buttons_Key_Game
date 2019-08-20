/****************************************************************************
** Meta object code from reading C++ file 'gamegui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QT_App_GameGUI/gamegui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameGUI_t {
    QByteArrayData data[8];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameGUI_t qt_meta_stringdata_GameGUI = {
    {
QT_MOC_LITERAL(0, 0, 7), // "GameGUI"
QT_MOC_LITERAL(1, 8, 12), // "handleButton"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 1), // "c"
QT_MOC_LITERAL(4, 24, 18), // "on_Restart_clicked"
QT_MOC_LITERAL(5, 43, 18), // "on_ButtonA_clicked"
QT_MOC_LITERAL(6, 62, 18), // "on_ButtonB_clicked"
QT_MOC_LITERAL(7, 81, 18) // "on_ButtonC_clicked"

    },
    "GameGUI\0handleButton\0\0c\0on_Restart_clicked\0"
    "on_ButtonA_clicked\0on_ButtonB_clicked\0"
    "on_ButtonC_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameGUI[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Char,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameGUI *_t = static_cast<GameGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleButton((*reinterpret_cast< const char(*)>(_a[1]))); break;
        case 1: _t->on_Restart_clicked(); break;
        case 2: _t->on_ButtonA_clicked(); break;
        case 3: _t->on_ButtonB_clicked(); break;
        case 4: _t->on_ButtonC_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject GameGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameGUI.data,
      qt_meta_data_GameGUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GameGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
