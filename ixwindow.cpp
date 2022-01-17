#include "ixwindow.h"
#include <math.h>
#include <QString>

#include <ixwindowfocushandler.h>
#include <ixwindowtabhandler.h>
#include <qquickwindow.h>

IXWindow::IXWindow(QQuickItem *parent) : QQuickItem(parent)
{
    setFiltersChildMouseEvents(true);
}

void IXWindow::setup()
{
    auto parent = this->parentItem();

    this->setWidth(_baseWidth);
    this->setHeight(_baseHeight);

    connect(parent, &QQuickItem::widthChanged, this, &IXWindow::windowResized);
    connect(parent, &QQuickItem::heightChanged, this, &IXWindow::windowResized);

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("verticalCenter", parent->property("verticalCenter"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("horizontalCenter", parent->property("horizontalCenter"));

    windowResized();
}

void IXWindow::setupFocusHandler()
{
    IXWindowFocusHandler::inst().setParentItem(parentItem());
    IXWindowFocusHandler::inst().stackBefore(this);
}

void IXWindow::setupTabHandler()
{
    IXWindowTabHandler::inst().setParentItem(parentItem());
}

void IXWindow::componentComplete()
{
    QQuickItem::componentComplete();
    if(!parentItem())
    {
        qDebug("No parent item");
        return;
    }

    this->setup();
    this->setupFocusHandler();
    this->setupTabHandler();
}

void IXWindow::windowResized()
{
    qreal scaleW = 1.0f;
    qreal scaleH = 1.0f;
    qreal appliedScale = 1.0f;

    qreal parentWidth = parentItem()->width();
    qreal parentHeight = parentItem()->height();

    if(parentWidth < this->_baseWidth) {
        scaleW = parentWidth / this->_baseWidth;
    }

    if(parentHeight < this->_baseHeight) {
        scaleH = parentHeight / this->_baseHeight;
    }
    appliedScale = fmin(scaleW, scaleH);

    this->setWidth(parentWidth / appliedScale);
    this->setHeight(parentHeight / appliedScale);
    this->setScale(appliedScale);
}

bool IXWindow::childMouseEventFilter(QQuickItem *item, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        auto activeFocusItem = window()->activeFocusItem();
        if(activeFocusItem != item)
            activeFocusItem->setFocus(false);
    }

    return false;
}
