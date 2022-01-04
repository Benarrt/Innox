#include "ixtextfield.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

IXTextField::IXTextField()
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
    EM_ASM({
        var element = document.getElementById("qtcanvas");
        element.inputMode = "text";
        element.blur();
        element.focus({preventScroll:true});
    });

    qDebug("IXTextField focusIn");
}

void IXTextField::focusOut()
{
    EM_ASM({
        var element = document.getElementById("qtcanvas");
        element.inputMode = "none";
        element.blur();
        element.focus({preventScroll:true});
    });

    qDebug("IXTextField focusOut");
}
