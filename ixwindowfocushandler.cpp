#include "ixwindowfocushandler.h"
#include <QQuickWindow>

IXWindowFocusHandler::IXWindowFocusHandler(QQuickItem *parent) : QQuickItem(parent)
{
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptTouchEvents(true);
    setFlag(ItemAcceptsInputMethod, true);
    connect(this, &IXWindowFocusHandler::parentChanged, this, &IXWindowFocusHandler::onParentChanged);
}

void IXWindowFocusHandler::onParentChanged(QQuickItem* parentItem)
{
    qDebug("FOCUSHANDLER COMPLS");

    connect(parentItem, &QQuickItem::widthChanged, this, &IXWindowFocusHandler::windowResized);
    connect(parentItem, &QQuickItem::heightChanged, this, &IXWindowFocusHandler::windowResized);

    windowResized();
}

void IXWindowFocusHandler::windowResized()
{
    this->setWidth(this->parentItem()->width());
    this->setHeight(this->parentItem()->height());
}

void IXWindowFocusHandler::mousePressEvent(QMouseEvent *event)
{
    auto activeFocusItem = window()->activeFocusItem();
    if(activeFocusItem)
        activeFocusItem->setFocus(false);

    event->ignore();
}
