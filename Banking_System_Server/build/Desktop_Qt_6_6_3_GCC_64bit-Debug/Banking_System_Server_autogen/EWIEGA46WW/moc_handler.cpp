/****************************************************************************
** Meta object code from reading C++ file 'handler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../handler.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSHandlerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSHandlerENDCLASS = QtMocHelpers::stringData(
    "Handler",
    "handleLogout",
    "",
    "QTcpSocket*",
    "socket",
    "isLoggedIn",
    "handleGetAccountNumber",
    "handleGetAccountNumberAdmin",
    "username",
    "handleGetBalance",
    "handleGetBalanceAdmin",
    "accountNum",
    "handleGetTransactionHisory",
    "count",
    "handleMakeTransaction",
    "amount",
    "handleGetTransactionHisoryAdmin",
    "handleTransfer",
    "toAcc",
    "createUser",
    "requestData",
    "handleUpdateUser",
    "handleDeleteUser",
    "parseJSONFromRequest",
    "QJsonObject&",
    "jsonObject",
    "saveUserDatabaseToFile",
    "handleLogin",
    "password"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHandlerENDCLASS_t {
    uint offsetsAndSizes[58];
    char stringdata0[8];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[7];
    char stringdata5[11];
    char stringdata6[23];
    char stringdata7[28];
    char stringdata8[9];
    char stringdata9[17];
    char stringdata10[22];
    char stringdata11[11];
    char stringdata12[27];
    char stringdata13[6];
    char stringdata14[22];
    char stringdata15[7];
    char stringdata16[32];
    char stringdata17[15];
    char stringdata18[6];
    char stringdata19[11];
    char stringdata20[12];
    char stringdata21[17];
    char stringdata22[17];
    char stringdata23[21];
    char stringdata24[13];
    char stringdata25[11];
    char stringdata26[23];
    char stringdata27[12];
    char stringdata28[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHandlerENDCLASS_t qt_meta_stringdata_CLASSHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Handler"
        QT_MOC_LITERAL(8, 12),  // "handleLogout"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(34, 6),  // "socket"
        QT_MOC_LITERAL(41, 10),  // "isLoggedIn"
        QT_MOC_LITERAL(52, 22),  // "handleGetAccountNumber"
        QT_MOC_LITERAL(75, 27),  // "handleGetAccountNumberAdmin"
        QT_MOC_LITERAL(103, 8),  // "username"
        QT_MOC_LITERAL(112, 16),  // "handleGetBalance"
        QT_MOC_LITERAL(129, 21),  // "handleGetBalanceAdmin"
        QT_MOC_LITERAL(151, 10),  // "accountNum"
        QT_MOC_LITERAL(162, 26),  // "handleGetTransactionHisory"
        QT_MOC_LITERAL(189, 5),  // "count"
        QT_MOC_LITERAL(195, 21),  // "handleMakeTransaction"
        QT_MOC_LITERAL(217, 6),  // "amount"
        QT_MOC_LITERAL(224, 31),  // "handleGetTransactionHisoryAdmin"
        QT_MOC_LITERAL(256, 14),  // "handleTransfer"
        QT_MOC_LITERAL(271, 5),  // "toAcc"
        QT_MOC_LITERAL(277, 10),  // "createUser"
        QT_MOC_LITERAL(288, 11),  // "requestData"
        QT_MOC_LITERAL(300, 16),  // "handleUpdateUser"
        QT_MOC_LITERAL(317, 16),  // "handleDeleteUser"
        QT_MOC_LITERAL(334, 20),  // "parseJSONFromRequest"
        QT_MOC_LITERAL(355, 12),  // "QJsonObject&"
        QT_MOC_LITERAL(368, 10),  // "jsonObject"
        QT_MOC_LITERAL(379, 22),  // "saveUserDatabaseToFile"
        QT_MOC_LITERAL(402, 11),  // "handleLogin"
        QT_MOC_LITERAL(414, 8)   // "password"
    },
    "Handler",
    "handleLogout",
    "",
    "QTcpSocket*",
    "socket",
    "isLoggedIn",
    "handleGetAccountNumber",
    "handleGetAccountNumberAdmin",
    "username",
    "handleGetBalance",
    "handleGetBalanceAdmin",
    "accountNum",
    "handleGetTransactionHisory",
    "count",
    "handleMakeTransaction",
    "amount",
    "handleGetTransactionHisoryAdmin",
    "handleTransfer",
    "toAcc",
    "createUser",
    "requestData",
    "handleUpdateUser",
    "handleDeleteUser",
    "parseJSONFromRequest",
    "QJsonObject&",
    "jsonObject",
    "saveUserDatabaseToFile",
    "handleLogin",
    "password"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHandlerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x08,    1 /* Private */,
       5,    1,  113,    2, 0x08,    3 /* Private */,
       6,    1,  116,    2, 0x08,    5 /* Private */,
       7,    2,  119,    2, 0x08,    7 /* Private */,
       9,    1,  124,    2, 0x08,   10 /* Private */,
      10,    2,  127,    2, 0x08,   12 /* Private */,
      12,    2,  132,    2, 0x08,   15 /* Private */,
      14,    2,  137,    2, 0x08,   18 /* Private */,
      16,    3,  142,    2, 0x08,   21 /* Private */,
      17,    3,  149,    2, 0x08,   25 /* Private */,
      19,    2,  156,    2, 0x08,   29 /* Private */,
      21,    2,  161,    2, 0x08,   32 /* Private */,
      22,    2,  166,    2, 0x08,   35 /* Private */,
      23,    2,  171,    2, 0x08,   38 /* Private */,
      26,    0,  176,    2, 0x08,   41 /* Private */,
      27,    3,  177,    2, 0x08,   42 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    8,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   11,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   13,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   15,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int,    4,   11,   13,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int,    4,   18,   15,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   20,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 24,   20,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    8,   28,

       0        // eod
};

Q_CONSTINIT const QMetaObject Handler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Handler, std::true_type>,
        // method 'handleLogout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'isLoggedIn'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'handleGetAccountNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'handleGetAccountNumberAdmin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'handleGetBalance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'handleGetBalanceAdmin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'handleGetTransactionHisory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleMakeTransaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleGetTransactionHisoryAdmin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleTransfer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'createUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'handleUpdateUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'handleDeleteUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'parseJSONFromRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        // method 'saveUserDatabaseToFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Handler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Handler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleLogout((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 1: { bool _r = _t->isLoggedIn((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->handleGetAccountNumber((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 3: _t->handleGetAccountNumberAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->handleGetBalance((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 5: _t->handleGetBalanceAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->handleGetTransactionHisory((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->handleMakeTransaction((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->handleGetTransactionHisoryAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->handleTransfer((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->createUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 11: _t->handleUpdateUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 12: _t->handleDeleteUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 13: _t->parseJSONFromRequest((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[2]))); break;
        case 14: _t->saveUserDatabaseToFile(); break;
        case 15: _t->handleLogin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Handler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Handler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Handler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
