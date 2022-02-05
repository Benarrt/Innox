#include "ixwindow.h"
#include "ixwindowfocushandler.h"
#include "ixwindowtabhandler.h"
#include "ixwindownavigationhandler.h"
#include "ixregistry.h"

#include <math.h>
#include <QString>

#include <qquickwindow.h>

IXWindow::IXWindow(QQuickItem *parent) : QQuickItem(parent)
{
    IXRegistry::inst().addToRegistry(this);
    setFiltersChildMouseEvents(true);
}

void IXWindow::setup()
{
    this->setWidth(_baseWidth);
    this->setHeight(_baseHeight);

    connect(_component, &QQuickItem::widthChanged, this, &IXWindow::onWindowResized);
    connect(_component, &QQuickItem::heightChanged, this, &IXWindow::onWindowResized);

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("verticalCenter", _component->property("verticalCenter"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("horizontalCenter", _component->property("horizontalCenter"));

    onWindowResized();
}

void IXWindow::setupFocusHandler()
{
    IXWindowFocusHandler::inst().setParentItem(_component);
    IXWindowFocusHandler::inst().stackBefore(this);
}

void IXWindow::setupTabHandler()
{
    IXWindowTabHandler::inst().setParentItem(_component);
}

void IXWindow::setupNavigationHandler()
{
    IXWindowNavigationHandler::inst().setParentItem(_component);
    connect(&IXWindowNavigationHandler::inst(), &IXWindowNavigationHandler::handleBack,
            this, &IXWindow::onHandleBack);
}

void IXWindow::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());

    this->setup();
    this->setupFocusHandler();
    this->setupTabHandler();
    this->setupNavigationHandler();
}

void IXWindow::onWindowResized()
{
    /*qreal scaleW = 1.0f;
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
    this->setScale(appliedScale);*/

    qreal desiredW = _component->width() > _baseWidth ? _baseWidth : _component->width();
    qreal scaleW = desiredW / this->width();
    qreal scaleH = _component->height()/this->height();

    //Scale is sometimess off and you can see 1-2pixels off
    scaleH += 0.01;
    scaleW += 0.01;

    auto ixWindowScale = this->findChild<QObject*>("ixWindowScale");
    ixWindowScale->setProperty("xScale", scaleW);
    ixWindowScale->setProperty("yScale", scaleH);
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

void IXWindow::onHandleBack()
{
    auto handleBackPopup = this->findChild<QQuickItem*>("handleBackPopup");
    if(handleBackPopup)
        handleBackPopup->setVisible(true);
}
