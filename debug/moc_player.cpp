/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_player_t {
    QByteArrayData data[15];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_player_t qt_meta_stringdata_player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "player"
QT_MOC_LITERAL(1, 7, 5), // "shoot"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 14), // "BackGroundMove"
QT_MOC_LITERAL(4, 29, 6), // "Skill0"
QT_MOC_LITERAL(5, 36, 6), // "Skill1"
QT_MOC_LITERAL(6, 43, 6), // "Skill2"
QT_MOC_LITERAL(7, 50, 6), // "Skill3"
QT_MOC_LITERAL(8, 57, 6), // "Skill4"
QT_MOC_LITERAL(9, 64, 8), // "collided"
QT_MOC_LITERAL(10, 73, 11), // "notcollided"
QT_MOC_LITERAL(11, 85, 7), // "succeed"
QT_MOC_LITERAL(12, 93, 6), // "failed"
QT_MOC_LITERAL(13, 100, 8), // "DecBlood"
QT_MOC_LITERAL(14, 109, 11) // "FreeFalling"

    },
    "player\0shoot\0\0BackGroundMove\0Skill0\0"
    "Skill1\0Skill2\0Skill3\0Skill4\0collided\0"
    "notcollided\0succeed\0failed\0DecBlood\0"
    "FreeFalling"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    0,   87,    2, 0x06 /* Public */,
      11,    0,   88,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   91,    2, 0x0a /* Public */,

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

       0        // eod
};

void player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        player *_t = static_cast<player *>(_o);
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
        case 9: _t->succeed(); break;
        case 10: _t->failed(); break;
        case 11: _t->DecBlood(); break;
        case 12: _t->FreeFalling(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::shoot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::BackGroundMove)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::Skill0)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::Skill1)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::Skill2)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::Skill3)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::Skill4)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::collided)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::notcollided)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::succeed)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::failed)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&player::DecBlood)) {
                *result = 11;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject player::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_player.data,
      qt_meta_data_player,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *player::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_player.stringdata0))
        return static_cast<void*>(const_cast< player*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< player*>(this));
    return QObject::qt_metacast(_clname);
}

int player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void player::shoot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void player::BackGroundMove()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void player::Skill0()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void player::Skill1()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void player::Skill2()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void player::Skill3()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void player::Skill4()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void player::collided()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void player::notcollided()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void player::succeed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void player::failed()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void player::DecBlood()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
