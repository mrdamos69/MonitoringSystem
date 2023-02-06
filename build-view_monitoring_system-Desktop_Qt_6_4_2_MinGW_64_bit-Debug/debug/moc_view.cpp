/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../view_monitoring_system/view.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_view_t {
    uint offsetsAndSizes[16];
    char stringdata0[5];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[7];
    char stringdata5[13];
    char stringdata6[8];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_view_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_view_t qt_meta_stringdata_view = {
    {
        QT_MOC_LITERAL(0, 4),  // "view"
        QT_MOC_LITERAL(5, 25),  // "triggeredGroupActionUpper"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 8),  // "QAction*"
        QT_MOC_LITERAL(41, 6),  // "action"
        QT_MOC_LITERAL(48, 12),  // "watcher_file"
        QT_MOC_LITERAL(61, 7),  // "settext"
        QT_MOC_LITERAL(69, 10)   // "start_slot"
    },
    "view",
    "triggeredGroupActionUpper",
    "",
    "QAction*",
    "action",
    "watcher_file",
    "settext",
    "start_slot"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_view[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x08,    1 /* Private */,
       5,    0,   41,    2, 0x08,    3 /* Private */,
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject view::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_view.offsetsAndSizes,
    qt_meta_data_view,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_view_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<view, std::true_type>,
        // method 'triggeredGroupActionUpper'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'watcher_file'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'settext'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<view *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->triggeredGroupActionUpper((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 1: _t->watcher_file(); break;
        case 2: _t->settext(); break;
        case 3: _t->start_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
