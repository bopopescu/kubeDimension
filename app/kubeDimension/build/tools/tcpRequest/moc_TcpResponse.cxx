/****************************************************************************
** Meta object code from reading C++ file 'TcpResponse.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tools/tcpRequest/TcpResponse.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpResponse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpResponse[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   12,   12,   12, 0x08,
      64,   52,   12,   12, 0x08,
     107,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpResponse[] = {
    "TcpResponse\0\0detectionReceived()\0"
    "readReceivedData()\0socketError\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "connectionLost()\0"
};

void TcpResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpResponse *_t = static_cast<TcpResponse *>(_o);
        switch (_id) {
        case 0: _t->detectionReceived(); break;
        case 1: _t->readReceivedData(); break;
        case 2: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: _t->connectionLost(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TcpResponse::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpResponse::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpResponse,
      qt_meta_data_TcpResponse, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpResponse::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpResponse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpResponse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpResponse))
        return static_cast<void*>(const_cast< TcpResponse*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpResponse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TcpResponse::detectionReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
