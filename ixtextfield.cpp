#include "ixtextfield.h"
#include "ixshadowtextfield.h"
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

IXTextField::IXTextField() : _textValue("")
{

}

void IXTextField::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    connect(parentItem(), &QQuickItem::focusChanged, this, &IXTextField::onParentFocusChanged);
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
}

void IXTextField::focusOut()
{
    IXShadowTextField::inst().removeTextField(this);
    EM_ASM({
        window.blurShadowTextField();
    });
}

void IXTextField::setTextValue(quint16 cursorPos, const QString& data)
{
    _textValue = data;
    emit textUpdated(cursorPos, _textValue);
}

void IXTextField::cursorPositionChanged(quint16 pos)
{
    qDebug("cursorPositionChanged");
    qDebug(QString::number(pos).toLocal8Bit());
    EM_ASM({
        if(!window.moveShadowTextFieldCursor) {
            return;
        }
        window.moveShadowTextFieldCursor($0);
    }, pos);
}
