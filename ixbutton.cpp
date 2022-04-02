#include "ixbutton.h"

IXButton::IXButton(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXButton::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());


}

