/****************************************************************************
** Meta object code from reading C++ file 'smartcalc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "smartcalc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smartcalc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_smartcalc_t {
    QByteArrayData data[15];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_smartcalc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_smartcalc_t qt_meta_stringdata_smartcalc = {
    {
QT_MOC_LITERAL(0, 0, 9), // "smartcalc"
QT_MOC_LITERAL(1, 10, 9), // "push_nums"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 19), // "on_push_dot_clicked"
QT_MOC_LITERAL(4, 41, 21), // "on_push_erase_clicked"
QT_MOC_LITERAL(5, 63, 22), // "on_push_pl_min_clicked"
QT_MOC_LITERAL(6, 86, 17), // "on_push_C_clicked"
QT_MOC_LITERAL(7, 104, 19), // "on_push_sum_clicked"
QT_MOC_LITERAL(8, 124, 18), // "on_push_CE_clicked"
QT_MOC_LITERAL(9, 143, 19), // "on_push_sub_clicked"
QT_MOC_LITERAL(10, 163, 20), // "on_push_mult_clicked"
QT_MOC_LITERAL(11, 184, 20), // "on_push_bkt1_clicked"
QT_MOC_LITERAL(12, 205, 18), // "on_push_eq_clicked"
QT_MOC_LITERAL(13, 224, 20), // "on_push_bkt2_clicked"
QT_MOC_LITERAL(14, 245, 19) // "on_push_div_clicked"

    },
    "smartcalc\0push_nums\0\0on_push_dot_clicked\0"
    "on_push_erase_clicked\0on_push_pl_min_clicked\0"
    "on_push_C_clicked\0on_push_sum_clicked\0"
    "on_push_CE_clicked\0on_push_sub_clicked\0"
    "on_push_mult_clicked\0on_push_bkt1_clicked\0"
    "on_push_eq_clicked\0on_push_bkt2_clicked\0"
    "on_push_div_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_smartcalc[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void smartcalc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<smartcalc *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->push_nums(); break;
        case 1: _t->on_push_dot_clicked(); break;
        case 2: _t->on_push_erase_clicked(); break;
        case 3: _t->on_push_pl_min_clicked(); break;
        case 4: _t->on_push_C_clicked(); break;
        case 5: _t->on_push_sum_clicked(); break;
        case 6: _t->on_push_CE_clicked(); break;
        case 7: _t->on_push_sub_clicked(); break;
        case 8: _t->on_push_mult_clicked(); break;
        case 9: _t->on_push_bkt1_clicked(); break;
        case 10: _t->on_push_eq_clicked(); break;
        case 11: _t->on_push_bkt2_clicked(); break;
        case 12: _t->on_push_div_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject smartcalc::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_smartcalc.data,
    qt_meta_data_smartcalc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *smartcalc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *smartcalc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_smartcalc.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int smartcalc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
