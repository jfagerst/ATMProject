/****************************************************************************
** Meta object code from reading C++ file 'tapahtumat.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bank-automat/tapahtumat.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tapahtumat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
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
struct qt_meta_stringdata_CLASSTapahtumatENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTapahtumatENDCLASS = QtMocHelpers::stringData(
    "Tapahtumat",
    "on_btnTapahtumat_clicked",
    "",
    "showTapahtumatSlot",
    "QNetworkReply*",
    "reply",
    "on_btntakaisin_clicked",
    "on_btnseuraava_clicked",
    "on_btnedellinen_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTapahtumatENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[11];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[15];
    char stringdata5[6];
    char stringdata6[23];
    char stringdata7[23];
    char stringdata8[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTapahtumatENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTapahtumatENDCLASS_t qt_meta_stringdata_CLASSTapahtumatENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Tapahtumat"
        QT_MOC_LITERAL(11, 24),  // "on_btnTapahtumat_clicked"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 18),  // "showTapahtumatSlot"
        QT_MOC_LITERAL(56, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(71, 5),  // "reply"
        QT_MOC_LITERAL(77, 22),  // "on_btntakaisin_clicked"
        QT_MOC_LITERAL(100, 22),  // "on_btnseuraava_clicked"
        QT_MOC_LITERAL(123, 23)   // "on_btnedellinen_clicked"
    },
    "Tapahtumat",
    "on_btnTapahtumat_clicked",
    "",
    "showTapahtumatSlot",
    "QNetworkReply*",
    "reply",
    "on_btntakaisin_clicked",
    "on_btnseuraava_clicked",
    "on_btnedellinen_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTapahtumatENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    1,   45,    2, 0x08,    2 /* Private */,
       6,    0,   48,    2, 0x08,    4 /* Private */,
       7,    0,   49,    2, 0x08,    5 /* Private */,
       8,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Tapahtumat::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSTapahtumatENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTapahtumatENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTapahtumatENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Tapahtumat, std::true_type>,
        // method 'on_btnTapahtumat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTapahtumatSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'on_btntakaisin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnseuraava_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnedellinen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Tapahtumat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tapahtumat *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnTapahtumat_clicked(); break;
        case 1: _t->showTapahtumatSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 2: _t->on_btntakaisin_clicked(); break;
        case 3: _t->on_btnseuraava_clicked(); break;
        case 4: _t->on_btnedellinen_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Tapahtumat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tapahtumat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTapahtumatENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Tapahtumat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
