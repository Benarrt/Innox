#include "ixtextfield.h"
#include "ixshadowtextfield.h"
#include "ixwindowfocushandler.h"

IXTextField::IXTextField(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXTextField::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    parentItem()->setAcceptHoverEvents(true);
    parentItem()->setActiveFocusOnTab(true);
    parentItem()->setProperty("selectByMouse", true);

    //QObject::connect(parentItem(), &QQuickItem::focusChanged, this, &IXTextField::onParentFocusChanged);
    QObject::connect(parentItem(), &QQuickItem::activeFocusChanged, this, &IXTextField::onParentFocusChanged);
    QObject::connect(parentItem(), SIGNAL(selectionEndChanged()), this, SLOT(selectionChanged()));
    QObject::connect(parentItem(), SIGNAL(selectionStartChanged()), this, SLOT(selectionChanged()));
}

void IXTextField::onParentFocusChanged(bool focus)
{
    if(focus)
        focusIn();
    else
        focusOut();
}

void IXTextField::focusIn()
{
    qDebug("FocusIN");
    auto textValue = parentItem()->property("text").toString();
    IXShadowTextField::inst().addTextField(this, textValue);
}

void IXTextField::focusOut()
{
    qDebug("FocusOUT");
    IXShadowTextField::inst().removeTextField(this);
}

void IXTextField::setTextValue(const QString& data)
{
    auto textValue = parentItem()->property("text").toString();
    if(data == textValue)
       return;
    parentItem()->setProperty("text", data);
}

void IXTextField::setSelection(quint16 posBeg, quint16 posEnd)
{
    auto cursorPos = parentItem()->property("cursorPosition").toInt();
    auto selecionStart = parentItem()->property("selecionStart").toInt();
    auto selecionEnd = parentItem()->property("selecionEnd").toInt();

    if(selecionStart == posBeg && selecionEnd == posEnd && cursorPos == selecionStart)
        return;

    if(posBeg == posEnd)
    {
        parentItem()->setProperty("cursorPosition", posEnd);
        return;
    }

    QMetaObject::invokeMethod(parentItem(), "select",
            Q_ARG(int, posBeg),  Q_ARG(int, posEnd));
}

void IXTextField::selectionChanged()
{
    auto selecionStart = parentItem()->property("selecionStart").toInt();
    auto selecionEnd = parentItem()->property("selecionEnd").toInt();
    auto cursorPosition = parentItem()->property("cursorPosition").toInt();

    if(selecionStart == 0 && selecionEnd == 0)
        IXShadowTextField::inst().setShadowTextFieldSelection(cursorPosition, cursorPosition);
    else
        IXShadowTextField::inst().setShadowTextFieldSelection(selecionStart, selecionEnd);
}
