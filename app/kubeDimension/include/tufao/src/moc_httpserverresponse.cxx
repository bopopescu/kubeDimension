/****************************************************************************
** Meta object code from reading C++ file 'httpserverresponse.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "httpserverresponse.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpserverresponse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tufao__HttpServerResponse[] = {

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
      27,   26,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   26,   38,   26, 0x0a,
      91,   59,   38,   26, 0x0a,
     149,  125,   38,   26, 0x0a,
     194,  175,   38,   26, 0x0a,
     228,  217,   38,   26, 0x0a,
     249,  243,   38,   26, 0x0a,
     275,  267,   38,   26, 0x0a,
     319,  296,   38,   26, 0x0a,
     353,  243,   38,   26, 0x0a,
     369,   26,   38,   26, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_Tufao__HttpServerResponse[] = {
    "Tufao::HttpServerResponse\0\0finished()\0"
    "bool\0writeContinue()\0"
    "statusCode,reasonPhrase,headers\0"
    "writeHead(int,QByteArray,Headers)\0"
    "statusCode,reasonPhrase\0"
    "writeHead(int,QByteArray)\0statusCode,headers\0"
    "writeHead(int,Headers)\0statusCode\0"
    "writeHead(int)\0chunk\0write(QByteArray)\0"
    "headers\0addTrailers(Headers)\0"
    "headerName,headerValue\0"
    "addTrailer(QByteArray,QByteArray)\0"
    "end(QByteArray)\0end()\0"
};

void Tufao::HttpServerResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HttpServerResponse *_t = static_cast<HttpServerResponse *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: { bool _r = _t->writeContinue();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->writeHead((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const Headers(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->writeHead((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->writeHead((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const Headers(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->writeHead((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->addTrailers((*reinterpret_cast< const Headers(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->addTrailer((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->end((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->end();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tufao::HttpServerResponse::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tufao::HttpServerResponse::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tufao__HttpServerResponse,
      qt_meta_data_Tufao__HttpServerResponse, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tufao::HttpServerResponse::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tufao::HttpServerResponse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tufao::HttpServerResponse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__HttpServerResponse))
        return static_cast<void*>(const_cast< HttpServerResponse*>(this));
    return QObject::qt_metacast(_clname);
}

int Tufao::HttpServerResponse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Tufao::HttpServerResponse::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
