/****************************************************************************
** Meta object code from reading C++ file 'httppluginserver.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "httppluginserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httppluginserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__HttpPluginServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      52,   30,   25,   24, 0x0a,
     149,  132,   25,   24, 0x2a,
     217,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__HttpPluginServer[] = {
    "Tufao::HttpPluginServer\0\0bool\0"
    "request,response,args\0"
    "handleRequest(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*,QSt"
    "ringList)\0"
    "request,response\0"
    "handleRequest(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)\0"
    "reloadConfig()\0"
};

void Tufao::HttpPluginServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HttpPluginServer *_t = static_cast<HttpPluginServer *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->handleRequest((*reinterpret_cast< Tufao::HttpServerRequest*(*)>(_a[1])),(*reinterpret_cast< Tufao::HttpServerResponse*(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->handleRequest((*reinterpret_cast< Tufao::HttpServerRequest*(*)>(_a[1])),(*reinterpret_cast< Tufao::HttpServerResponse*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->reloadConfig(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::HttpPluginServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::HttpPluginServer::staticMetaObject = {
    { &AbstractHttpServerRequestHandler::staticMetaObject, qt_meta_stringdata_Tufao__HttpPluginServer,
      qt_meta_data_Tufao__HttpPluginServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::HttpPluginServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::HttpPluginServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::HttpPluginServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__HttpPluginServer))
        return static_cast<void*>(const_cast< HttpPluginServer*>(this));
    return AbstractHttpServerRequestHandler::qt_metacast(_clname);
}

int Tufao::HttpPluginServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractHttpServerRequestHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
