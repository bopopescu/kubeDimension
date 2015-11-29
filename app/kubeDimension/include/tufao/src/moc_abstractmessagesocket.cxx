/****************************************************************************
** Meta object code from reading C++ file 'abstractmessagesocket.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "abstractmessagesocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractmessagesocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__AbstractMessageSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x05,
      42,   29,   29,   29, 0x05,
      61,   57,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   29,   29,   29, 0x0a,
      97,   57,   92,   29, 0x0a,
     121,   29,   29,   29, 0x08,
     135,   29,   29,   29, 0x08,

 // properties: name, type, flags
     152,   92, 0x01095801,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__AbstractMessageSocket[] = {
    "Tufao::AbstractMessageSocket\0\0connected()\0"
    "disconnected()\0msg\0newMessage(QByteArray)\0"
    "close()\0bool\0sendMessage(QByteArray)\0"
    "onConnected()\0onDisconnected()\0connected\0"
};

void Tufao::AbstractMessageSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AbstractMessageSocket *_t = static_cast<AbstractMessageSocket *>(_o);
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->newMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->close(); break;
        case 4: { bool _r = _t->sendMessage((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->onConnected(); break;
        case 6: _t->onDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::AbstractMessageSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::AbstractMessageSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tufao__AbstractMessageSocket,
      qt_meta_data_Tufao__AbstractMessageSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::AbstractMessageSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::AbstractMessageSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::AbstractMessageSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__AbstractMessageSocket))
        return static_cast<void*>(const_cast< AbstractMessageSocket*>(this));
    return QObject::qt_metacast(_clname);
}

int Tufao::AbstractMessageSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isConnected(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Tufao::AbstractMessageSocket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Tufao::AbstractMessageSocket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Tufao::AbstractMessageSocket::newMessage(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
