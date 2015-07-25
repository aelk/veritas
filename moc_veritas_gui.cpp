/****************************************************************************
** Meta object code from reading C++ file 'veritas_gui.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "veritas_gui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'veritas_gui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Veritas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      20,    8,    8,    8, 0x0a,
      31,    8,    8,    8, 0x0a,
      44,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Veritas[] = {
    "Veritas\0\0getFiles()\0startApp()\0"
    "openREADME()\0exitApp()\0"
};

void Veritas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Veritas *_t = static_cast<Veritas *>(_o);
        switch (_id) {
        case 0: _t->getFiles(); break;
        case 1: _t->startApp(); break;
        case 2: _t->openREADME(); break;
        case 3: _t->exitApp(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Veritas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Veritas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Veritas,
      qt_meta_data_Veritas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Veritas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Veritas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Veritas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Veritas))
        return static_cast<void*>(const_cast< Veritas*>(this));
    return QWidget::qt_metacast(_clname);
}

int Veritas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
