/****************************************************************************
** Meta object code from reading C++ file 'soundapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QQ_pro/api/soundapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoundAPI_t {
    QByteArrayData data[15];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoundAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoundAPI_t qt_meta_stringdata_SoundAPI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SoundAPI"
QT_MOC_LITERAL(1, 9, 9), // "playSound"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "setPlayCount"
QT_MOC_LITERAL(4, 33, 9), // "playCount"
QT_MOC_LITERAL(5, 43, 17), // "setPlayAlarmSound"
QT_MOC_LITERAL(6, 61, 14), // "playAlarmSound"
QT_MOC_LITERAL(7, 76, 12), // "setSoundPath"
QT_MOC_LITERAL(8, 89, 9), // "soundPath"
QT_MOC_LITERAL(9, 99, 4), // "play"
QT_MOC_LITERAL(10, 104, 9), // "soundName"
QT_MOC_LITERAL(11, 114, 9), // "setVolume"
QT_MOC_LITERAL(12, 124, 6), // "Volume"
QT_MOC_LITERAL(13, 131, 5), // "start"
QT_MOC_LITERAL(14, 137, 4) // "stop"

    },
    "SoundAPI\0playSound\0\0setPlayCount\0"
    "playCount\0setPlayAlarmSound\0playAlarmSound\0"
    "setSoundPath\0soundPath\0play\0soundName\0"
    "setVolume\0Volume\0start\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundAPI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,
      13,    0,   70,    2, 0x0a /* Public */,
      14,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SoundAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoundAPI *_t = static_cast<SoundAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playSound(); break;
        case 1: _t->setPlayCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setPlayAlarmSound((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setSoundPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->play((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->start(); break;
        case 7: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObject SoundAPI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SoundAPI.data,
      qt_meta_data_SoundAPI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SoundAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SoundAPI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SoundAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
