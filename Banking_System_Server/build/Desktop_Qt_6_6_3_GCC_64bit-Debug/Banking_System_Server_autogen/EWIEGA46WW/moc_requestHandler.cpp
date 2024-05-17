/****************************************************************************
** Meta object code from reading C++ file 'requestHandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../requestHandler.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'requestHandler.h' doesn't include <QObject>."
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
    "isLoggedIn",
    "",
    "QTcpSocket*",
    "socket",
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
    "handleLogin",
    "password",
    "handleGetRequest",
    "handlePostRequest",
    "sendJsonResponse",
    "clientSocket",
    "sendResponse",
    "data"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHandlerENDCLASS_t {
    uint offsetsAndSizes[66];
    char stringdata0[8];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[7];
    char stringdata5[23];
    char stringdata6[28];
    char stringdata7[9];
    char stringdata8[17];
    char stringdata9[22];
    char stringdata10[11];
    char stringdata11[27];
    char stringdata12[6];
    char stringdata13[22];
    char stringdata14[7];
    char stringdata15[32];
    char stringdata16[15];
    char stringdata17[6];
    char stringdata18[11];
    char stringdata19[12];
    char stringdata20[17];
    char stringdata21[17];
    char stringdata22[21];
    char stringdata23[13];
    char stringdata24[11];
    char stringdata25[12];
    char stringdata26[9];
    char stringdata27[17];
    char stringdata28[18];
    char stringdata29[17];
    char stringdata30[13];
    char stringdata31[13];
    char stringdata32[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHandlerENDCLASS_t qt_meta_stringdata_CLASSHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Handler"
        QT_MOC_LITERAL(8, 10),  // "isLoggedIn"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(32, 6),  // "socket"
        QT_MOC_LITERAL(39, 22),  // "handleGetAccountNumber"
        QT_MOC_LITERAL(62, 27),  // "handleGetAccountNumberAdmin"
        QT_MOC_LITERAL(90, 8),  // "username"
        QT_MOC_LITERAL(99, 16),  // "handleGetBalance"
        QT_MOC_LITERAL(116, 21),  // "handleGetBalanceAdmin"
        QT_MOC_LITERAL(138, 10),  // "accountNum"
        QT_MOC_LITERAL(149, 26),  // "handleGetTransactionHisory"
        QT_MOC_LITERAL(176, 5),  // "count"
        QT_MOC_LITERAL(182, 21),  // "handleMakeTransaction"
        QT_MOC_LITERAL(204, 6),  // "amount"
        QT_MOC_LITERAL(211, 31),  // "handleGetTransactionHisoryAdmin"
        QT_MOC_LITERAL(243, 14),  // "handleTransfer"
        QT_MOC_LITERAL(258, 5),  // "toAcc"
        QT_MOC_LITERAL(264, 10),  // "createUser"
        QT_MOC_LITERAL(275, 11),  // "requestData"
        QT_MOC_LITERAL(287, 16),  // "handleUpdateUser"
        QT_MOC_LITERAL(304, 16),  // "handleDeleteUser"
        QT_MOC_LITERAL(321, 20),  // "parseJSONFromRequest"
        QT_MOC_LITERAL(342, 12),  // "QJsonObject&"
        QT_MOC_LITERAL(355, 10),  // "jsonObject"
        QT_MOC_LITERAL(366, 11),  // "handleLogin"
        QT_MOC_LITERAL(378, 8),  // "password"
        QT_MOC_LITERAL(387, 16),  // "handleGetRequest"
        QT_MOC_LITERAL(404, 17),  // "handlePostRequest"
        QT_MOC_LITERAL(422, 16),  // "sendJsonResponse"
        QT_MOC_LITERAL(439, 12),  // "clientSocket"
        QT_MOC_LITERAL(452, 12),  // "sendResponse"
        QT_MOC_LITERAL(465, 4)   // "data"
    },
    "Handler",
    "isLoggedIn",
    "",
    "QTcpSocket*",
    "socket",
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
    "handleLogin",
    "password",
    "handleGetRequest",
    "handlePostRequest",
    "sendJsonResponse",
    "clientSocket",
    "sendResponse",
    "data"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHandlerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x08,    1 /* Private */,
       5,    1,  125,    2, 0x08,    3 /* Private */,
       6,    2,  128,    2, 0x08,    5 /* Private */,
       8,    1,  133,    2, 0x08,    8 /* Private */,
       9,    2,  136,    2, 0x08,   10 /* Private */,
      11,    2,  141,    2, 0x08,   13 /* Private */,
      13,    2,  146,    2, 0x08,   16 /* Private */,
      15,    3,  151,    2, 0x08,   19 /* Private */,
      16,    3,  158,    2, 0x08,   23 /* Private */,
      18,    2,  165,    2, 0x08,   27 /* Private */,
      20,    2,  170,    2, 0x08,   30 /* Private */,
      21,    2,  175,    2, 0x08,   33 /* Private */,
      22,    2,  180,    2, 0x08,   36 /* Private */,
      25,    3,  185,    2, 0x08,   39 /* Private */,
      27,    2,  192,    2, 0x08,   43 /* Private */,
      28,    2,  197,    2, 0x08,   46 /* Private */,
      29,    2,  202,    2, 0x08,   49 /* Private */,
      31,    2,  207,    2, 0x08,   52 /* Private */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   10,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   12,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   14,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int,    4,   10,   12,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int,    4,   17,   14,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   19,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 23,   19,   24,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    7,   26,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QJsonObject,   30,   24,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,   30,   32,

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
        // method 'handleLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleGetRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'handlePostRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'sendJsonResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
    >,
    nullptr
} };

void Handler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Handler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->isLoggedIn((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->handleGetAccountNumber((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 2: _t->handleGetAccountNumberAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->handleGetBalance((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1]))); break;
        case 4: _t->handleGetBalanceAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->handleGetTransactionHisory((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->handleMakeTransaction((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->handleGetTransactionHisoryAdmin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->handleTransfer((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->createUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 10: _t->handleUpdateUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 11: _t->handleDeleteUser((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 12: _t->parseJSONFromRequest((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[2]))); break;
        case 13: _t->handleLogin((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 14: _t->handleGetRequest((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 15: _t->handlePostRequest((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 16: _t->sendJsonResponse((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 17: _t->sendResponse((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
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
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 14:
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
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        case 17:
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
