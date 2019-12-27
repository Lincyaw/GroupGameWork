/****************************************************************************
** Meta object code from reading C++ file 'anemy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../anemy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anemy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_anemy_t {
    QByteArrayData data[17];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_anemy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_anemy_t qt_meta_stringdata_anemy = {
    {
QT_MOC_LITERAL(0, 0, 5), // "anemy"
QT_MOC_LITERAL(1, 6, 5), // "shoot"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 14), // "BackGroundMove"
QT_MOC_LITERAL(4, 28, 6), // "Skill0"
QT_MOC_LITERAL(5, 35, 6), // "Skill1"
QT_MOC_LITERAL(6, 42, 6), // "Skill2"
QT_MOC_LITERAL(7, 49, 6), // "Skill3"
QT_MOC_LITERAL(8, 56, 6), // "Skill4"
QT_MOC_LITERAL(9, 63, 8), // "collided"
QT_MOC_LITERAL(10, 72, 11), // "notcollided"
QT_MOC_LITERAL(11, 84, 6), // "Behurt"
QT_MOC_LITERAL(12, 91, 10), // "Recoveried"
QT_MOC_LITERAL(13, 102, 8), // "BeKilled"
QT_MOC_LITERAL(14, 111, 11), // "AttackedByJ"
QT_MOC_LITERAL(15, 123, 11), // "AttackedByK"
QT_MOC_LITERAL(16, 135, 11) // "AttackedByL"

    },
    "anemy\0shoot\0\0BackGroundMove\0Skill0\0"
    "Skill1\0Skill2\0Skill3\0Skill4\0collided\0"
    "notcollided\0Behurt\0Recoveried\0BeKilled\0"
    "AttackedByJ\0AttackedByK\0AttackedByL"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_anemy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,
      11,    0,   98,    2, 0x06 /* Public */,
      12,    0,   99,    2, 0x06 /* Public */,
      13,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
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

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void anemy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        anemy *_t = static_cast<anemy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shoot(); break;
        case 1: _t->BackGroundMove(); break;
        case 2: _t->Skill0(); break;
        case 3: _t->Skill1(); break;
        case 4: _t->Skill2(); break;
        case 5: _t->Skill3(); break;
        case 6: _t->Skill4(); break;
        case 7: _t->collided(); break;
        case 8: _t->notcollided(); break;
        case 9: _t->Behurt(); break;
        case 10: _t->Recoveried(); break;
        case 11: _t->BeKilled(); break;
        case 12: _t->AttackedByJ(); break;
        case 13: _t->AttackedByK(); break;
        case 14: _t->AttackedByL(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::shoot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::BackGroundMove)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Skill0)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Skill1)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Skill2)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Skill3)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Skill4)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::collided)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::notcollided)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Behurt)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::Recoveried)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (anemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&anemy::BeKilled)) {
                *result = 11;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject anemy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_anemy.data,
      qt_meta_data_anemy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *anemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *anemy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_anemy.stringdata0))
        return static_cast<void*>(const_cast< anemy*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< anemy*>(this));
    return QObject::qt_metacast(_clname);
}

int anemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void anemy::shoot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void anemy::BackGroundMove()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void anemy::Skill0()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void anemy::Skill1()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void anemy::Skill2()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void anemy::Skill3()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void anemy::Skill4()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void anemy::collided()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void anemy::notcollided()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void anemy::Behurt()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void anemy::Recoveried()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void anemy::BeKilled()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
