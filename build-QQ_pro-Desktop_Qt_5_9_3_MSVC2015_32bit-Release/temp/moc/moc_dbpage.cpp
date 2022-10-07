/****************************************************************************
** Meta object code from reading C++ file 'dbpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QQ_pro/api/dbpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DbConnectThread_t {
    QByteArrayData data[10];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DbConnectThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DbConnectThread_t qt_meta_stringdata_DbConnectThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DbConnectThread"
QT_MOC_LITERAL(1, 16, 16), // "Connection_click"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "setConnName"
QT_MOC_LITERAL(4, 46, 2), // "IP"
QT_MOC_LITERAL(5, 49, 4), // "port"
QT_MOC_LITERAL(6, 54, 7), // "sqlname"
QT_MOC_LITERAL(7, 62, 2), // "sa"
QT_MOC_LITERAL(8, 65, 8), // "password"
QT_MOC_LITERAL(9, 74, 8) // "connName"

    },
    "DbConnectThread\0Connection_click\0\0"
    "setConnName\0IP\0port\0sqlname\0sa\0password\0"
    "connName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DbConnectThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    6,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,    9,

       0        // eod
};

void DbConnectThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DbConnectThread *_t = static_cast<DbConnectThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Connection_click((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setConnName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DbConnectThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DbConnectThread::Connection_click)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DbConnectThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DbConnectThread.data,
      qt_meta_data_DbConnectThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DbConnectThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbConnectThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DbConnectThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DbConnectThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DbConnectThread::Connection_click(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_DbCountThread_t {
    QByteArrayData data[10];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DbCountThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DbCountThread_t qt_meta_stringdata_DbCountThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DbCountThread"
QT_MOC_LITERAL(1, 14, 12), // "receiveCount"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "count"
QT_MOC_LITERAL(4, 34, 4), // "msec"
QT_MOC_LITERAL(5, 39, 11), // "setConnName"
QT_MOC_LITERAL(6, 51, 8), // "connName"
QT_MOC_LITERAL(7, 60, 6), // "setSql"
QT_MOC_LITERAL(8, 67, 3), // "sql"
QT_MOC_LITERAL(9, 71, 6) // "select"

    },
    "DbCountThread\0receiveCount\0\0count\0"
    "msec\0setConnName\0connName\0setSql\0sql\0"
    "select"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DbCountThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x0a /* Public */,
       7,    1,   42,    2, 0x0a /* Public */,
       9,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void DbCountThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DbCountThread *_t = static_cast<DbCountThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->setConnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->select(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DbCountThread::*_t)(quint32 , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DbCountThread::receiveCount)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DbCountThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DbCountThread.data,
      qt_meta_data_DbCountThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DbCountThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbCountThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DbCountThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DbCountThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DbCountThread::receiveCount(quint32 _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_DbPage_t {
    QByteArrayData data[66];
    char stringdata0[785];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DbPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DbPage_t qt_meta_stringdata_DbPage = {
    {
QT_MOC_LITERAL(0, 0, 6), // "DbPage"
QT_MOC_LITERAL(1, 7, 11), // "receivePage"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "pageCurrent"
QT_MOC_LITERAL(4, 32, 9), // "pageCount"
QT_MOC_LITERAL(5, 42, 11), // "resultCount"
QT_MOC_LITERAL(6, 54, 13), // "resultCurrent"
QT_MOC_LITERAL(7, 68, 12), // "receiveCount"
QT_MOC_LITERAL(8, 81, 5), // "count"
QT_MOC_LITERAL(9, 87, 4), // "msec"
QT_MOC_LITERAL(10, 92, 5), // "first"
QT_MOC_LITERAL(11, 98, 8), // "previous"
QT_MOC_LITERAL(12, 107, 4), // "next"
QT_MOC_LITERAL(13, 112, 4), // "last"
QT_MOC_LITERAL(14, 117, 8), // "bindData"
QT_MOC_LITERAL(15, 126, 3), // "sql"
QT_MOC_LITERAL(16, 130, 17), // "slot_receiveCount"
QT_MOC_LITERAL(17, 148, 10), // "setControl"
QT_MOC_LITERAL(18, 159, 11), // "QTableView*"
QT_MOC_LITERAL(19, 171, 9), // "tableView"
QT_MOC_LITERAL(20, 181, 7), // "QLabel*"
QT_MOC_LITERAL(21, 189, 12), // "labPageCount"
QT_MOC_LITERAL(22, 202, 14), // "labPageCurrent"
QT_MOC_LITERAL(23, 217, 14), // "labResultCount"
QT_MOC_LITERAL(24, 232, 16), // "labResultCurrent"
QT_MOC_LITERAL(25, 249, 9), // "labResult"
QT_MOC_LITERAL(26, 259, 7), // "labInfo"
QT_MOC_LITERAL(27, 267, 16), // "QAbstractButton*"
QT_MOC_LITERAL(28, 284, 8), // "btnFirst"
QT_MOC_LITERAL(29, 293, 6), // "btnPre"
QT_MOC_LITERAL(30, 300, 7), // "btnNext"
QT_MOC_LITERAL(31, 308, 7), // "btnLast"
QT_MOC_LITERAL(32, 316, 9), // "countName"
QT_MOC_LITERAL(33, 326, 8), // "connName"
QT_MOC_LITERAL(34, 335, 11), // "setConnName"
QT_MOC_LITERAL(35, 347, 9), // "setDbType"
QT_MOC_LITERAL(36, 357, 6), // "DbType"
QT_MOC_LITERAL(37, 364, 6), // "dbType"
QT_MOC_LITERAL(38, 371, 12), // "setTableName"
QT_MOC_LITERAL(39, 384, 9), // "tableName"
QT_MOC_LITERAL(40, 394, 15), // "setSelectColumn"
QT_MOC_LITERAL(41, 410, 12), // "selectColumn"
QT_MOC_LITERAL(42, 423, 11), // "setOrderSql"
QT_MOC_LITERAL(43, 435, 8), // "orderSql"
QT_MOC_LITERAL(44, 444, 11), // "setWhereSql"
QT_MOC_LITERAL(45, 456, 8), // "whereSql"
QT_MOC_LITERAL(46, 465, 16), // "setResultCurrent"
QT_MOC_LITERAL(47, 482, 14), // "setColumnNames"
QT_MOC_LITERAL(48, 497, 14), // "QList<QString>"
QT_MOC_LITERAL(49, 512, 11), // "columnNames"
QT_MOC_LITERAL(50, 524, 15), // "setColumnWidths"
QT_MOC_LITERAL(51, 540, 10), // "QList<int>"
QT_MOC_LITERAL(52, 551, 12), // "columnWidths"
QT_MOC_LITERAL(53, 564, 12), // "setAllCenter"
QT_MOC_LITERAL(54, 577, 9), // "allCenter"
QT_MOC_LITERAL(55, 587, 20), // "setAlignCenterColumn"
QT_MOC_LITERAL(56, 608, 17), // "alignCenterColumn"
QT_MOC_LITERAL(57, 626, 19), // "setAlignRightColumn"
QT_MOC_LITERAL(58, 646, 16), // "alignRightColumn"
QT_MOC_LITERAL(59, 663, 20), // "setInsertColumnIndex"
QT_MOC_LITERAL(60, 684, 17), // "insertColumnIndex"
QT_MOC_LITERAL(61, 702, 19), // "setInsertColumnName"
QT_MOC_LITERAL(62, 722, 16), // "insertColumnName"
QT_MOC_LITERAL(63, 739, 20), // "setInsertColumnWidth"
QT_MOC_LITERAL(64, 760, 17), // "insertColumnWidth"
QT_MOC_LITERAL(65, 778, 6) // "select"

    },
    "DbPage\0receivePage\0\0pageCurrent\0"
    "pageCount\0resultCount\0resultCurrent\0"
    "receiveCount\0count\0msec\0first\0previous\0"
    "next\0last\0bindData\0sql\0slot_receiveCount\0"
    "setControl\0QTableView*\0tableView\0"
    "QLabel*\0labPageCount\0labPageCurrent\0"
    "labResultCount\0labResultCurrent\0"
    "labResult\0labInfo\0QAbstractButton*\0"
    "btnFirst\0btnPre\0btnNext\0btnLast\0"
    "countName\0connName\0setConnName\0setDbType\0"
    "DbType\0dbType\0setTableName\0tableName\0"
    "setSelectColumn\0selectColumn\0setOrderSql\0"
    "orderSql\0setWhereSql\0whereSql\0"
    "setResultCurrent\0setColumnNames\0"
    "QList<QString>\0columnNames\0setColumnWidths\0"
    "QList<int>\0columnWidths\0setAllCenter\0"
    "allCenter\0setAlignCenterColumn\0"
    "alignCenterColumn\0setAlignRightColumn\0"
    "alignRightColumn\0setInsertColumnIndex\0"
    "insertColumnIndex\0setInsertColumnName\0"
    "insertColumnName\0setInsertColumnWidth\0"
    "insertColumnWidth\0select"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DbPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  144,    2, 0x06 /* Public */,
       7,    2,  153,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  158,    2, 0x08 /* Private */,
      11,    0,  159,    2, 0x08 /* Private */,
      12,    0,  160,    2, 0x08 /* Private */,
      13,    0,  161,    2, 0x08 /* Private */,
      14,    1,  162,    2, 0x08 /* Private */,
      16,    2,  165,    2, 0x08 /* Private */,
      17,   13,  170,    2, 0x0a /* Public */,
      17,   12,  197,    2, 0x2a /* Public | MethodCloned */,
      34,    1,  222,    2, 0x0a /* Public */,
      35,    1,  225,    2, 0x0a /* Public */,
      38,    1,  228,    2, 0x0a /* Public */,
      40,    1,  231,    2, 0x0a /* Public */,
      42,    1,  234,    2, 0x0a /* Public */,
      44,    1,  237,    2, 0x0a /* Public */,
      46,    1,  240,    2, 0x0a /* Public */,
      47,    1,  243,    2, 0x0a /* Public */,
      50,    1,  246,    2, 0x0a /* Public */,
      53,    1,  249,    2, 0x0a /* Public */,
      55,    1,  252,    2, 0x0a /* Public */,
      57,    1,  255,    2, 0x0a /* Public */,
      59,    1,  258,    2, 0x0a /* Public */,
      61,    1,  261,    2, 0x0a /* Public */,
      63,    1,  264,    2, 0x0a /* Public */,
      65,    0,  267,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::Double,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::UInt, QMetaType::Double,    8,    9,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 27, QMetaType::QString, QMetaType::QString,   19,   21,   22,   23,   24,   25,   26,   28,   29,   30,   31,   32,   33,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 27, QMetaType::QString,   19,   21,   22,   23,   24,   25,   26,   28,   29,   30,   31,   32,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 48,   49,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, QMetaType::Bool,   54,
    QMetaType::Void, 0x80000000 | 51,   56,
    QMetaType::Void, 0x80000000 | 51,   58,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void,

       0        // eod
};

void DbPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DbPage *_t = static_cast<DbPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivePage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 1: _t->receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->first(); break;
        case 3: _t->previous(); break;
        case 4: _t->next(); break;
        case 5: _t->last(); break;
        case 6: _t->bindData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->slot_receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->setControl((*reinterpret_cast< QTableView*(*)>(_a[1])),(*reinterpret_cast< QLabel*(*)>(_a[2])),(*reinterpret_cast< QLabel*(*)>(_a[3])),(*reinterpret_cast< QLabel*(*)>(_a[4])),(*reinterpret_cast< QLabel*(*)>(_a[5])),(*reinterpret_cast< QLabel*(*)>(_a[6])),(*reinterpret_cast< QLabel*(*)>(_a[7])),(*reinterpret_cast< QAbstractButton*(*)>(_a[8])),(*reinterpret_cast< QAbstractButton*(*)>(_a[9])),(*reinterpret_cast< QAbstractButton*(*)>(_a[10])),(*reinterpret_cast< QAbstractButton*(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13]))); break;
        case 9: _t->setControl((*reinterpret_cast< QTableView*(*)>(_a[1])),(*reinterpret_cast< QLabel*(*)>(_a[2])),(*reinterpret_cast< QLabel*(*)>(_a[3])),(*reinterpret_cast< QLabel*(*)>(_a[4])),(*reinterpret_cast< QLabel*(*)>(_a[5])),(*reinterpret_cast< QLabel*(*)>(_a[6])),(*reinterpret_cast< QLabel*(*)>(_a[7])),(*reinterpret_cast< QAbstractButton*(*)>(_a[8])),(*reinterpret_cast< QAbstractButton*(*)>(_a[9])),(*reinterpret_cast< QAbstractButton*(*)>(_a[10])),(*reinterpret_cast< QAbstractButton*(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12]))); break;
        case 10: _t->setConnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setDbType((*reinterpret_cast< const DbType(*)>(_a[1]))); break;
        case 12: _t->setTableName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->setSelectColumn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->setOrderSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->setWhereSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->setResultCurrent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setColumnNames((*reinterpret_cast< const QList<QString>(*)>(_a[1]))); break;
        case 18: _t->setColumnWidths((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 19: _t->setAllCenter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->setAlignCenterColumn((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 21: _t->setAlignRightColumn((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 22: _t->setInsertColumnIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->setInsertColumnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->setInsertColumnWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->select(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 10:
            case 9:
            case 8:
            case 7:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableView* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 10:
            case 9:
            case 8:
            case 7:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableView* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DbPage::*_t)(quint32 , quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DbPage::receivePage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DbPage::*_t)(quint32 , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DbPage::receiveCount)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DbPage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DbPage.data,
      qt_meta_data_DbPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DbPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DbPage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DbPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void DbPage::receivePage(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DbPage::receiveCount(quint32 _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
