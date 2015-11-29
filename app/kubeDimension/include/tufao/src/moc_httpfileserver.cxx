/****************************************************************************
** Meta object code from reading C++ file 'httpfileserver.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "httpfileserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpfileserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__HttpFileServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      46,   28,   23,   22, 0x0a,
     143,  126,   23,   22, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__HttpFileServer[] = {
    "Tufao::HttpFileServer\0\0bool\0"
    "request,response,\0"
    "handleRequest(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*,QSt"
    "ringList)\0"
    "request,response\0"
    "handleRequest(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)\0"
};

void Tufao::HttpFileServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HttpFileServer *_t = static_cast<HttpFileServer *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->handleRequest((*reinterpret_cast< Tufao::HttpServerRequest*(*)>(_a[1])),(*reinterpret_cast< Tufao::HttpServerResponse*(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->handleRequest((*reinterpret_cast< Tufao::HttpServerRequest*(*)>(_a[1])),(*reinterpret_cast< Tufao::HttpServerResponse*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::HttpFileServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::HttpFileServer::staticMetaObject = {
    { &AbstractHttpServerRequestHandler::staticMetaObject, qt_meta_stringdata_Tufao__HttpFileServer,
      qt_meta_data_Tufao__HttpFileServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::HttpFileServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::HttpFileServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::HttpFileServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__HttpFileServer))
        return static_cast<void*>(const_cast< HttpFileServer*>(this));
    return AbstractHttpServerRequestHandler::qt_metacast(_clname);
}

int Tufao::HttpFileServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractHttpServerRequestHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
