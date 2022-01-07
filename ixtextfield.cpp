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
    qDebug("IXTextField focusInEvent");
}

void IXTextField::focusOutEvent(QFocusEvent *e)
{
    QQuickItem::focusOutEvent(e);
    qDebug("IXTextField focusOutEvent");
}

void IXTextField::focusIn()
{
    IXShadowTextField::inst().addTextField(this);
    EM_ASM({
        var currentValue = Module.UTF16ToString($0);
        window.focusShadowTextField(currentValue);
    }, _textValue.data());

    qDebug("IXTextField focusIn");
}

void IXTextField::focusOut()
{
    IXShadowTextField::inst().removeTextField(this);
    EM_ASM({
        window.blurShadowTextField();
    });

    qDebug("IXTextField focusOut");
}

void IXTextField::setTextValue(const QString& data)
{
    _textValue = data;
    emit textUpdated(_textValue);
}
