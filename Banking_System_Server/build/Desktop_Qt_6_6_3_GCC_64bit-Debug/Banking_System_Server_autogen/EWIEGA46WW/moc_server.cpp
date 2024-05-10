/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../server.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSServerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSServerENDCLASS = QtMocHelpers::stringData(
    "Server",
    "handleLogout",
    "",
    "QTcpSocket*",
    "socket",
    "isLoggedIn",
    "readRequest",
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
struct qt_meta_stringdata_CLASSServerENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[7];
    char stringdata5[11];
    char stringdata6[12];
    char stringdata7[23];
    char stringdata8[28];
    char stringdata9[9];
    char stringdata10[17];
    char stringdata11[22];
    char stringdata12[11];
    char stringdata13[27];
    char stringdata14[6];
    char stringdata15[22];
    char stringdata16[7];
    char stringdata17[32];
    char stringdata18[15];
    char stringdata19[6];
    char stringdata20[11];
    char stringdata21[12];
    char stringdata22[17];
    char stringdata23[17];
    char stringdata24[21];
    char stringdata25[13];
    char stringdata26[11];
    char stringdata27[23];
    char stringdata28[12];
    char stringdata29[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSServerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSServerENDCLASS_t qt_meta_stringdata_CLASSServerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Server"
        QT_MOC_LITERAL(7, 12),  // "handleLogout"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(33, 6),  // "socket"
        QT_MOC_LITERAL(40, 10),  // "isLoggedIn"
        QT_MOC_LITERAL(51, 11),  // "readRequest"
        QT_MOC_LITERAL(63, 22),  // "handleGetAccountNumber"
        QT_MOC_LITERAL(86, 27),  // "handleGetAccountNumberAdmin"
        QT_MOC_LITERAL(114, 8),  // "username"
        QT_MOC_LITERAL(123, 16),  // "handleGetBalance"
        QT_MOC_LITERAL(140, 21),  // "handleGetBalanceAdmin"
        QT_MOC_LITERAL(162, 10),  // "accountNum"
        QT_MOC_LITERAL(173, 26),  // "handleGetTransactionHisory"
        QT_MOC_LITERAL(200, 5),  // "count"
        QT_MOC_LITERAL(206, 21),  // "handleMakeTransaction"
        QT_MOC_LITERAL(228, 6),  // "amount"
        QT_MOC_LITERAL(235, 31),  // "handleGetTransactionHisoryAdmin"
        QT_MOC_LITERAL(267, 14),  // "handleTransfer"
        QT_MOC_LITERAL(282, 5),  // "toAcc"
        QT_MOC_LITERAL(288, 10),  // "createUser"
        QT_MOC_LITERAL(299, 11),  // "requestData"
        QT_MOC_LITERAL(311, 16),  // "handleUpdateUser"
        QT_MOC_LITERAL(328, 16),  // "handleDeleteUser"
        QT_MOC_LITERAL(345, 20),  // "parseJSONFromRequest"
        QT_MOC_LITERAL(366, 12),  // "QJsonObject&"
        QT_MOC_LITERAL(379, 10),  // "jsonObject"
        QT_MOC_LITERAL(390, 22),  // "saveUserDatabaseToFile"
        QT_MOC_LITERAL(413, 11),  // "handleLogin"
        QT_MOC_LITERAL(425, 8)   // "password"
    },
    "Server",
    "handleLogout",
    "",
    "QTcpSocket*",
    "socket",
    "isLoggedIn",
    "readRequest",
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

Q_CONSTINIT static const uint qt_meta_data_CLASSServerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x08,    1 /* Private */,
       5,    1,  119,    2, 0x08,    3 /* Private */,
       6,    0,  122,    2, 0x08,    5 /* Private */,
       7,    1,  123,    2, 0x08,    6 /* Private */,
       8,    2,  126,    2, 0x08,    8 /* Private */,
      10,    1,  131,    2, 0x08,   11 /* Private */,
      11,    2,  134,    2, 0x08,   13 /* Private */,
      13,    2,  139,    2, 0x08,   16 /* Private */,
      15,    2,  144,    2, 0x08,   19 /* Private */,
      17,    3,  149,    2, 0x08,   22 /* Private */,
      18,    3,  156,    2, 0x08,   26 /* Private */,
      20,    2,  163,    2, 0x08,   30 /* Private */,
      22,    2,  168,    2, 0x08,   33 /* Private */,
      23,    2,  173,    2, 0x08,   36 /* Private */,
      24,    2,  178,    2, 0x08,   39 /* Private */,
      27,    0,  183,    2, 0x08,   42 /* Private */,
      28,    3,  184,    2, 0x08,   43 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   12,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   14,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   16,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int,    4,   12,   14,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int,    4,   19,   16,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   21,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   21,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   21,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 25,   21,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    9,   29,

       0        // eod
};

Q_CONSTINIT const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_CLASSServerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSServerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSServerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Server, std::true_type>,
        // method 'handleLogout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'isLoggedIn'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'readRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleLogout((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 1: { bool _r = _t->isLoggedIn((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->readRequest(); break;
        case 3: _t->handleGetAccountNumber((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 4: _t->handleGetAccountNumberAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->handleGetBalance((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 6: _t->handleGetBalanceAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->handleGetTransactionHisory((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->handleMakeTransaction((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->handleGetTransactionHisoryAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->handleTransfer((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 11: _t->createUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 12: _t->handleUpdateUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 13: _t->handleDeleteUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 14: _t->parseJSONFromRequest((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[2]))); break;
        case 15: _t->saveUserDatabaseToFile(); break;
        case 16: _t->handleLogin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
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
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSServerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
