/****************************************************************************
** Meta object code from reading C++ file 'gamegui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamegui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,    9,    8,    8, 0x08,
      30,    8,    8,    8, 0x08,
      51,    8,    8,    8, 0x08,
      72,    8,    8,    8, 0x08,
      93,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameGUI[] = {
    "GameGUI\0\0c\0handleButton(char)\0"
    "on_Restart_clicked()\0on_ButtonA_clicked()\0"
    "on_ButtonB_clicked()\0on_ButtonC_clicked()\0"
};

void GameGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameGUI *_t = static_cast<GameGUI *>(_o);
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

const QMetaObjectExtraData GameGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameGUI,
      qt_meta_data_GameGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameGUI))
        return static_cast<void*>(const_cast< GameGUI*>(this));
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
