/****************************************************************************
** Meta object code from reading C++ file 'httpserver.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "httpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__HttpServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   18,   18,   18, 0x0a,
     128,  111,   18,   18, 0x08,
     149,   18,   18,   18, 0x08,
     171,  166,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__HttpServer[] = {
    "Tufao::HttpServer\0\0request,response\0"
    "requestReady(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)\0"
    "close()\0socketDescriptor\0onNewConnection(int)\0"
    "onRequestReady()\0head\0onUpgrade(QByteArray)\0"
};

void Tufao::HttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HttpServer *_t = static_cast<HttpServer *>(_o);
        switch (_id) {
        case 0: _t->requestReady((*reinterpret_cast< Tufao::HttpServerRequest*(*)>(_a[1])),(*reinterpret_cast< Tufao::HttpServerResponse*(*)>(_a[2]))); break;
        case 1: _t->close(); break;
        case 2: _t->onNewConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onRequestReady(); break;
        case 4: _t->onUpgrade((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::HttpServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::HttpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tufao__HttpServer,
      qt_meta_data_Tufao__HttpServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::HttpServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::HttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::HttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__HttpServer))
        return static_cast<void*>(const_cast< HttpServer*>(this));
    return QObject::qt_metacast(_clname);
}

int Tufao::HttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tufao::HttpServer::requestReady(Tufao::HttpServerRequest * _t1, Tufao::HttpServerResponse * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
