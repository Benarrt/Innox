/****************************************************************************
** Meta object code from reading C++ file 'ixwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ixwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ixwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IXWindow_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IXWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IXWindow_t qt_meta_stringdata_IXWindow = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IXWindow"
QT_MOC_LITERAL(1, 9, 16), // "componentChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "QQuickItem*"
QT_MOC_LITERAL(4, 39, 4), // "item"
QT_MOC_LITERAL(5, 44, 16), // "baseWidthChanged"
QT_MOC_LITERAL(6, 61, 17), // "baseHeightChanged"
QT_MOC_LITERAL(7, 79, 15), // "onWindowResized"
QT_MOC_LITERAL(8, 95, 12), // "onHandleBack"
QT_MOC_LITERAL(9, 108, 9), // "component"
QT_MOC_LITERAL(10, 118, 12), // "setComponent"
QT_MOC_LITERAL(11, 131, 9), // "baseWidth"
QT_MOC_LITERAL(12, 141, 10) // "baseHeight"

    },
    "IXWindow\0componentChanged\0\0QQuickItem*\0"
    "item\0baseWidthChanged\0baseHeightChanged\0"
    "onWindowResized\0onHandleBack\0component\0"
    "setComponent\0baseWidth\0baseHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IXWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       1,    0,   57,    2, 0x26 /* Public | MethodCloned */,
       5,    1,   58,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x02 /* Public */,
      10,    1,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    0x80000000 | 3,
    QMetaType::Void, 0x80000000 | 3,    9,

 // properties: name, type, flags
       9, 0x80000000 | 3, 0x0049510b,
      11, QMetaType::UShort, 0x00495003,
      12, QMetaType::UShort, 0x00495003,

 // properties: notify_signal_id
       0,
       2,
       3,

       0        // eod
};

void IXWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IXWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->componentChanged((*reinterpret_cast< QQuickItem*(*)>(_a[1]))); break;
        case 1: _t->componentChanged(); break;
        case 2: _t->baseWidthChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->baseHeightChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 4: _t->onWindowResized(); break;
        case 5: _t->onHandleBack(); break;
        case 6: { QQuickItem* _r = _t->component();
            if (_a[0]) *reinterpret_cast< QQuickItem**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setComponent((*reinterpret_cast< QQuickItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IXWindow::*)(QQuickItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IXWindow::componentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IXWindow::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IXWindow::baseWidthChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IXWindow::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IXWindow::baseHeightChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<IXWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQuickItem**>(_v) = _t->component(); break;
        case 1: *reinterpret_cast< quint16*>(_v) = _t->_baseWidth; break;
        case 2: *reinterpret_cast< quint16*>(_v) = _t->_baseHeight; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<IXWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setComponent(*reinterpret_cast< QQuickItem**>(_v)); break;
        case 1:
            if (_t->_baseWidth != *reinterpret_cast< quint16*>(_v)) {
                _t->_baseWidth = *reinterpret_cast< quint16*>(_v);
                Q_EMIT _t->baseWidthChanged(_t->_baseWidth);
            }
            break;
        case 2:
            if (_t->_baseHeight != *reinterpret_cast< quint16*>(_v)) {
                _t->_baseHeight = *reinterpret_cast< quint16*>(_v);
                Q_EMIT _t->baseHeightChanged(_t->_baseHeight);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject IXWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_IXWindow.data,
    qt_meta_data_IXWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IXWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IXWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IXWindow.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int IXWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void IXWindow::componentChanged(QQuickItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void IXWindow::baseWidthChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IXWindow::baseHeightChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
