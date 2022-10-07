/****************************************************************************
** Meta object code from reading C++ file 'protocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QQ_pro/api/protocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtocolCMD_t {
    QByteArrayData data[26];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtocolCMD_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtocolCMD_t qt_meta_stringdata_ProtocolCMD = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProtocolCMD"
QT_MOC_LITERAL(1, 12, 15), // "sendProtocolCMD"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "uint8_t*"
QT_MOC_LITERAL(4, 38, 7), // "uint8_t"
QT_MOC_LITERAL(5, 46, 18), // "sendProtocolUPSCMD"
QT_MOC_LITERAL(6, 65, 18), // "sendProtocolMCUCMD"
QT_MOC_LITERAL(7, 84, 12), // "sendSerialUp"
QT_MOC_LITERAL(8, 97, 9), // "UpLoadCmd"
QT_MOC_LITERAL(9, 107, 7), // "LoadCmd"
QT_MOC_LITERAL(10, 115, 14), // "sendSerialInfo"
QT_MOC_LITERAL(11, 130, 11), // "InfoLoadCmd"
QT_MOC_LITERAL(12, 142, 20), // "sendSerialControlCmd"
QT_MOC_LITERAL(13, 163, 10), // "ControlCmd"
QT_MOC_LITERAL(14, 174, 13), // "sendSerialUPS"
QT_MOC_LITERAL(15, 188, 9), // "unLoadCmd"
QT_MOC_LITERAL(16, 198, 13), // "tagUpLoadCmd&"
QT_MOC_LITERAL(17, 212, 12), // "unLoadCmdVer"
QT_MOC_LITERAL(18, 225, 17), // "unLoadProtocolCmd"
QT_MOC_LITERAL(19, 243, 11), // "ProtocolCmd"
QT_MOC_LITERAL(20, 255, 5), // "lenth"
QT_MOC_LITERAL(21, 261, 20), // "unLoadProtocolCmdUPS"
QT_MOC_LITERAL(22, 282, 13), // "UpLoadCmdUPS&"
QT_MOC_LITERAL(23, 296, 10), // "LoadCmdUPS"
QT_MOC_LITERAL(24, 307, 15), // "sendLoadVersion"
QT_MOC_LITERAL(25, 323, 12) // "sendLoadNULL"

    },
    "ProtocolCMD\0sendProtocolCMD\0\0uint8_t*\0"
    "uint8_t\0sendProtocolUPSCMD\0"
    "sendProtocolMCUCMD\0sendSerialUp\0"
    "UpLoadCmd\0LoadCmd\0sendSerialInfo\0"
    "InfoLoadCmd\0sendSerialControlCmd\0"
    "ControlCmd\0sendSerialUPS\0unLoadCmd\0"
    "tagUpLoadCmd&\0unLoadCmdVer\0unLoadProtocolCmd\0"
    "ProtocolCmd\0lenth\0unLoadProtocolCmdUPS\0"
    "UpLoadCmdUPS&\0LoadCmdUPS\0sendLoadVersion\0"
    "sendLoadNULL"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtocolCMD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    2,   84,    2, 0x06 /* Public */,
       6,    2,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   94,    2, 0x0a /* Public */,
      10,    1,   97,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      14,    1,  103,    2, 0x0a /* Public */,
      15,    2,  106,    2, 0x0a /* Public */,
      17,    1,  111,    2, 0x0a /* Public */,
      18,    3,  114,    2, 0x0a /* Public */,
      21,    3,  121,    2, 0x0a /* Public */,
      24,    0,  128,    2, 0x0a /* Public */,
      25,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 13,    9,
    QMetaType::Void, 0x80000000 | 4,    9,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 16,    9,    8,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 16,   19,   20,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 22,   19,   20,   23,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProtocolCMD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProtocolCMD *_t = static_cast<ProtocolCMD *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendProtocolCMD((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 1: _t->sendProtocolUPSCMD((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 2: _t->sendProtocolMCUCMD((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 3: _t->sendSerialUp((*reinterpret_cast< UpLoadCmd(*)>(_a[1]))); break;
        case 4: _t->sendSerialInfo((*reinterpret_cast< InfoLoadCmd(*)>(_a[1]))); break;
        case 5: _t->sendSerialControlCmd((*reinterpret_cast< ControlCmd(*)>(_a[1]))); break;
        case 6: _t->sendSerialUPS((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 7: _t->unLoadCmd((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< tagUpLoadCmd(*)>(_a[2]))); break;
        case 8: _t->unLoadCmdVer((*reinterpret_cast< uint8_t*(*)>(_a[1]))); break;
        case 9: _t->unLoadProtocolCmd((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< tagUpLoadCmd(*)>(_a[3]))); break;
        case 10: _t->unLoadProtocolCmdUPS((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< UpLoadCmdUPS(*)>(_a[3]))); break;
        case 11: _t->sendLoadVersion(); break;
        case 12: _t->sendLoadNULL(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ProtocolCMD::*_t)(uint8_t * , uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolCMD::sendProtocolCMD)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ProtocolCMD::*_t)(uint8_t * , uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolCMD::sendProtocolUPSCMD)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ProtocolCMD::*_t)(uint8_t * , uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolCMD::sendProtocolMCUCMD)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ProtocolCMD::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ProtocolCMD.data,
      qt_meta_data_ProtocolCMD,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProtocolCMD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtocolCMD::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtocolCMD.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProtocolCMD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ProtocolCMD::sendProtocolCMD(uint8_t * _t1, uint8_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProtocolCMD::sendProtocolUPSCMD(uint8_t * _t1, uint8_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProtocolCMD::sendProtocolMCUCMD(uint8_t * _t1, uint8_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
