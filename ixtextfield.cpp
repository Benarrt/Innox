#include "ixtextfield.h"
#include "ixshadowtextfield.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

IXTextField::IXTextField(QQuickItem* parent) : QQuickItem(parent), _textValue("")
{

}

void IXTextField::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    parentItem()->setProperty("selectByMouse", true);
    parentItem()->installEventFilter(this);
    QObject::connect(parentItem(), &QQuickItem::focusChanged, this, &IXTextField::onParentFocusChanged);
    //QObject::connect(parentItem(), SIGNAL(selectionEndChanged()), this, SLOT(selectionChanged()));
    //QObject::connect(parentItem(), SIGNAL(selectionStartChanged()), this, SLOT(selectionChanged()));
}

bool IXTextField::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonRelease ||
            event->type() == QEvent::TouchEnd)
    {
        selectionChanged();
    }
    return false;
}

void IXTextField::onParentFocusChanged(bool focus)
{
    if(focus)
        focusIn();
    else
        focusOut();
}

void IXTextField::focusInEvent(QFocusEvent *e)
{
    QQuickItem::focusInEvent(e);
}

void IXTextField::focusOutEvent(QFocusEvent *e)
{
    QQuickItem::focusOutEvent(e);
}

void IXTextField::focusIn()
{
    IXShadowTextField::inst().addTextField(this);
    EM_ASM({
        var currentValue = Module.UTF16ToString($0);
        window.focusShadowTextField(currentValue);
    }, _textValue.data());
    cursorPositionChanged();
}

void IXTextField::focusOut()
{
    IXShadowTextField::inst().removeTextField(this);
    EM_ASM({
        window.blurShadowTextField();
    });
}

void IXTextField::setTextValue(const QString& data)
{
    _textValue = data;
    parentItem()->setProperty("text", data);
}

void IXTextField::setSelection(quint16 posBeg, quint16 posEnd)
{
    if(posBeg >= posEnd)
    {
        parentItem()->setProperty("cursorPosition", posEnd);
        return;
    }
    QMetaObject::invokeMethod(parentItem(), "select",
            Q_ARG(int, posBeg),  Q_ARG(int, posEnd));
}

void IXTextField::cursorPositionChanged()
{
    auto pos = parentItem()->property("cursorPosition").toInt();
    EM_ASM({
        if(!window.moveShadowTextFieldCursor) {
            return;
        }
        window.moveShadowTextFieldCursor($0, $0);
    }, pos);
}

void IXTextField::selectionChanged()
{
    if(!parentItem()->property("selectByMouse").toBool())
    {
        return;
    }

    auto posBeg = parentItem()->property("selectionStart").toInt();
    auto posEnd = parentItem()->property("selectionEnd").toInt();

    EM_ASM({
        if(!window.moveShadowTextFieldCursor) {
            return;
        }
        window.moveShadowTextFieldCursor($0, $1);
    }, posBeg, posEnd);
}
