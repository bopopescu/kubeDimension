/****************************************************************************
** Meta object code from reading C++ file 'tcpserverwrapper.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcpserverwrapper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserverwrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__TcpServerWrapper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   25,   24,   24, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__TcpServerWrapper[] = {
    "Tufao::TcpServerWrapper\0\0socketDescriptor\0"
    "newConnection(int)\0"
};

void Tufao::TcpServerWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpServerWrapper *_t = static_cast<TcpServerWrapper *>(_o);
        switch (_id) {
        case 0: _t->newConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::TcpServerWrapper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::TcpServerWrapper::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_Tufao__TcpServerWrapper,
      qt_meta_data_Tufao__TcpServerWrapper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::TcpServerWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::TcpServerWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::TcpServerWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__TcpServerWrapper))
        return static_cast<void*>(const_cast< TcpServerWrapper*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int Tufao::TcpServerWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Tufao::TcpServerWrapper::newConnection(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
