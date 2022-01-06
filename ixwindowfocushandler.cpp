#include "ixwindowfocushandler.h"
#include <QQuickWindow>

IXWindowFocusHandler::IXWindowFocusHandler(QQuickItem *parent) : QQuickItem(parent)
{
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptTouchEvents(true);
    setFlag(ItemAcceptsInputMethod, true);
    connect(parent, &QQuickItem::widthChanged, this, &IXWindowFocusHandler::windowResized);
    connect(parent, &QQuickItem::heightChanged, this, &IXWindowFocusHandler::windowResized);
}

void IXWindowFocusHandler::mousePressEvent(QMouseEvent *event)
{
    auto activeFocusItem = window()->activeFocusItem();
    if(activeFocusItem)
        activeFocusItem->setFocus(false);

    event->ignore();
}

void IXWindowFocusHandler::touchEvent(QTouchEvent *event)
{
    auto activeFocusItem = window()->activeFocusItem();
    if(activeFocusItem)
        activeFocusItem->setFocus(false);

    event->ignore();
}

void IXWindowFocusHandler::windowResized()
{
    this->setWidth(this->parentItem()->width());
    this->setHeight(this->parentItem()->height());
}
