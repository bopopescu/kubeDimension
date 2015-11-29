/****************************************************************************
** Meta object code from reading C++ file 'websocket.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "websocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__WebSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   17,   17,   17, 0x0a,
      57,   53,   48,   17, 0x0a,
      81,   53,   48,   17, 0x0a,
     111,   53,   48,   17, 0x0a,
     139,   18,   48,   17, 0x0a,
     162,  156,   17,   17, 0x08,
     213,  206,   17,   17, 0x08,
     243,   17,   17,   17, 0x08,
     257,   17,   17,   17, 0x08,
     271,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__WebSocket[] = {
    "Tufao::WebSocket\0\0data\0pong(QByteArray)\0"
    "close()\0bool\0msg\0sendMessage(QByteArray)\0"
    "sendBinaryMessage(QByteArray)\0"
    "sendUtf8Message(QByteArray)\0"
    "ping(QByteArray)\0error\0"
    "onSocketError(QAbstractSocket::SocketError)\0"
    "errors\0onSslErrors(QList<QSslError>)\0"
    "onConnected()\0onReadyRead()\0"
    "onDisconnected()\0"
};

void Tufao::WebSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WebSocket *_t = static_cast<WebSocket *>(_o);
        switch (_id) {
        case 0: _t->pong((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->close(); break;
        case 2: { bool _r = _t->sendMessage((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->sendBinaryMessage((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->sendUtf8Message((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->ping((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->onSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 8: _t->onConnected(); break;
        case 9: _t->onReadyRead(); break;
        case 10: _t->onDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::WebSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::WebSocket::staticMetaObject = {
    { &AbstractMessageSocket::staticMetaObject, qt_meta_stringdata_Tufao__WebSocket,
      qt_meta_data_Tufao__WebSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::WebSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::WebSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::WebSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__WebSocket))
        return static_cast<void*>(const_cast< WebSocket*>(this));
    return AbstractMessageSocket::qt_metacast(_clname);
}

int Tufao::WebSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractMessageSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Tufao::WebSocket::pong(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
