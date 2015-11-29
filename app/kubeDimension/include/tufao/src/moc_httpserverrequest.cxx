/****************************************************************************
** Meta object code from reading C++ file 'httpserverrequest.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "httpserverrequest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpserverrequest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__HttpServerRequest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,
      68,   25,   25,   25, 0x05,
      81,   76,   25,   25, 0x05,
      98,   25,   25,   25, 0x05,
     104,   25,   25,   25, 0x05,
     117,  112,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
     137,   25,   25,   25, 0x08,
     151,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__HttpServerRequest[] = {
    "Tufao::HttpServerRequest\0\0"
    "ready(Tufao::HttpServerResponse::Options)\0"
    "ready()\0data\0data(QByteArray)\0end()\0"
    "close()\0head\0upgrade(QByteArray)\0"
    "onReadyRead()\0onTimeout()\0"
};

void Tufao::HttpServerRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HttpServerRequest *_t = static_cast<HttpServerRequest *>(_o);
        switch (_id) {
        case 0: _t->ready((*reinterpret_cast< Tufao::HttpServerResponse::Options(*)>(_a[1]))); break;
        case 1: _t->ready(); break;
        case 2: _t->data((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->end(); break;
        case 4: _t->close(); break;
        case 5: _t->upgrade((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->onReadyRead(); break;
        case 7: _t->onTimeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::HttpServerRequest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::HttpServerRequest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tufao__HttpServerRequest,
      qt_meta_data_Tufao__HttpServerRequest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::HttpServerRequest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::HttpServerRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::HttpServerRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__HttpServerRequest))
        return static_cast<void*>(const_cast< HttpServerRequest*>(this));
    return QObject::qt_metacast(_clname);
}

int Tufao::HttpServerRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Tufao::HttpServerRequest::ready(Tufao::HttpServerResponse::Options _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tufao::HttpServerRequest::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Tufao::HttpServerRequest::data(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Tufao::HttpServerRequest::end()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Tufao::HttpServerRequest::close()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Tufao::HttpServerRequest::upgrade(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
