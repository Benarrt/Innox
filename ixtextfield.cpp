#include "ixtextfield.h"
#include "ixshadowtextfield.h"

IXTextField::IXTextField(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXTextField::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    parentItem()->setAcceptHoverEvents(true);
    parentItem()->setActiveFocusOnTab(true);
    parentItem()->setProperty(META_PROPERTIES::selectByMouse, true);

    QObject::connect(parentItem(), &QQuickItem::activeFocusChanged, this, &IXTextField::onParentFocusChanged);
    QObject::connect(parentItem(), SIGNAL(selectionEndChanged()), this, SLOT(selectionChanged()));
    QObject::connect(parentItem(), SIGNAL(selectionStartChanged()), this, SLOT(selectionChanged()));
}

void IXTextField::onParentFocusChanged(bool focus)
{
    if(focus)
    {
        focusIn();
        selectionChanged();
    }
    else
        focusOut();
}

void IXTextField::focusIn()
{
    auto textValue = parentItem()->property(META_PROPERTIES::text).toString();
    IXShadowTextField::inst().addTextField(this, textValue);
}

void IXTextField::focusOut()
{
    IXShadowTextField::inst().removeTextField(this);
}

void IXTextField::setTextValue(const QString& data)
{
    auto textValue = parentItem()->property(META_PROPERTIES::text).toString();
    if(data == textValue)
       return;
    parentItem()->setProperty(META_PROPERTIES::text, data);
}

void IXTextField::setSelection(quint16 posBeg, quint16 posEnd)
{
    auto cursorPos = parentItem()->property(META_PROPERTIES::cursorPosition).toInt();
    auto selecionStart = parentItem()->property(META_PROPERTIES::selectionStart).toInt();
    auto selecionEnd = parentItem()->property(META_PROPERTIES::selectionEnd).toInt();

    if(selecionStart == posBeg && selecionEnd == posEnd && cursorPos == selecionStart)
        return;

    if(posBeg == posEnd)
    {
        parentItem()->setProperty(META_PROPERTIES::cursorPosition, posEnd);
        return;
    }

    QMetaObject::invokeMethod(parentItem(), META_METHODS::select,
            Q_ARG(int, posBeg),  Q_ARG(int, posEnd));
}

void IXTextField::selectionChanged()
{
    auto selecionStart = parentItem()->property(META_PROPERTIES::selectionStart).toInt();
    auto selecionEnd = parentItem()->property(META_PROPERTIES::selectionEnd).toInt();
    auto cursorPosition = parentItem()->property(META_PROPERTIES::cursorPosition).toInt();

    if(selecionStart == 0 && selecionEnd == 0)
        IXShadowTextField::inst().setShadowTextFieldSelection(cursorPosition, cursorPosition);
    else
        IXShadowTextField::inst().setShadowTextFieldSelection(selecionStart, selecionEnd);
}
