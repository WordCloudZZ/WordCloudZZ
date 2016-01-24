/****************************************************************************
** Meta object code from reading C++ file 'ComputingThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RandomSentencesGUI/ComputingThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComputingThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ComputingThread_t {
    QByteArrayData data[7];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComputingThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComputingThread_t qt_meta_stringdata_ComputingThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ComputingThread"
QT_MOC_LITERAL(1, 16, 14), // "computingEnded"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "Stats"
QT_MOC_LITERAL(4, 38, 19), // "computingProgressed"
QT_MOC_LITERAL(5, 58, 7), // "percent"
QT_MOC_LITERAL(6, 66, 21) // "computingProgressed_s"

    },
    "ComputingThread\0computingEnded\0\0Stats\0"
    "computingProgressed\0percent\0"
    "computingProgressed_s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComputingThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Double,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void ComputingThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComputingThread *_t = static_cast<ComputingThread *>(_o);
        switch (_id) {
        case 0: _t->computingEnded((*reinterpret_cast< Stats(*)>(_a[1]))); break;
        case 1: _t->computingProgressed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->computingProgressed_s((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ComputingThread::*_t)(Stats );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComputingThread::computingEnded)) {
                *result = 0;
            }
        }
        {
            typedef void (ComputingThread::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComputingThread::computingProgressed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ComputingThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ComputingThread.data,
      qt_meta_data_ComputingThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ComputingThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComputingThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ComputingThread.stringdata))
        return static_cast<void*>(const_cast< ComputingThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ComputingThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ComputingThread::computingEnded(Stats _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ComputingThread::computingProgressed(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
