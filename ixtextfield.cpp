#include "ixtextfield.h"
#include "ixshadowtextfield.h"

IXTextField::IXTextField(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXTextField::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());

    _component->setAcceptHoverEvents(true);
    _component->setActiveFocusOnTab(true);
    _component->setProperty(META_PROPERTIES::selectByMouse, true);

    QObject::connect(_component, &QQuickItem::activeFocusChanged, this, &IXTextField::onParentFocusChanged);
    QObject::connect(_component, SIGNAL(selectionEndChanged()), this, SLOT(selectionChanged()));
    QObject::connect(_component, SIGNAL(selectionStartChanged()), this, SLOT(selectionChanged()));
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
    auto textValue = _component->property(META_PROPERTIES::text).toString();
    IXShadowTextField::inst().addTextField(this, textValue);
}

void IXTextField::focusOut()
{
    IXShadowTextField::inst().removeTextField(this);
}

void IXTextField::setTextValue(const QString& data)
{
    auto textValue = _component->property(META_PROPERTIES::text).toString();
    if(data == textValue)
       return;
    _component->setProperty(META_PROPERTIES::text, data);
}

void IXTextField::setSelection(quint16 posBeg, quint16 posEnd)
{
    auto cursorPos = _component->property(META_PROPERTIES::cursorPosition).toInt();
    auto selecionStart = _component->property(META_PROPERTIES::selectionStart).toInt();
    auto selecionEnd = _component->property(META_PROPERTIES::selectionEnd).toInt();

    if(selecionStart == posBeg && selecionEnd == posEnd && cursorPos == selecionStart)
        return;

    if(posBeg == posEnd)
    {
        _component->setProperty(META_PROPERTIES::cursorPosition, posEnd);
        return;
    }

    QMetaObject::invokeMethod(_component, META_METHODS::select,
            Q_ARG(int, posBeg),  Q_ARG(int, posEnd));
}

void IXTextField::selectionChanged()
{
    auto selecionStart = _component->property(META_PROPERTIES::selectionStart).toInt();
    auto selecionEnd = _component->property(META_PROPERTIES::selectionEnd).toInt();
    auto cursorPosition = _component->property(META_PROPERTIES::cursorPosition).toInt();

    if(selecionStart == 0 && selecionEnd == 0)
        IXShadowTextField::inst().setShadowTextFieldSelection(cursorPosition, cursorPosition);
    else
        IXShadowTextField::inst().setShadowTextFieldSelection(selecionStart, selecionEnd);
}
