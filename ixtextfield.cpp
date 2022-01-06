#include "ixtextfield.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

IXTextField* IXTextField::inst = nullptr;

extern "C" {
        void EMSCRIPTEN_KEEPALIVE inputData(QChar* data)
        {
            QString k(data);
            free(data);
            qDebug("inputData");
            qDebug(k.toLocal8Bit());
            IXTextField::inst->setData(k);
        }
}

IXTextField::IXTextField()
{
    IXTextField::inst = this;

    QString name = QString::number(uint64_t(this));
    this->setObjectName(name);
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
        var qtCanvas = document.getElementById("qtcanvas");
        var input = document.getElementById("shadowTextField");
        qtCanvas.blur();
        input.hidden = false;
        input.focus({preventScroll:true});
    });

    qDebug("IXTextField focusIn");
}

void IXTextField::focusOut()
{
    EM_ASM({
        var qtCanvas = document.getElementById("qtcanvas");
        var input = document.getElementById("shadowTextField");
        input.blur();
        input.hidden = true;
        qtCanvas.focus();
        qtCanvas.scrollIntoView();
    });

    qDebug("IXTextField focusOut");
}
