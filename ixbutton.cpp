#include "ixbutton.h"

IXButton::IXButton(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXButton::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    parentItem()->setProperty(META_PROPERTIES::hoverEnabled, true);

}

