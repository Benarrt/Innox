#include "ixwindow.h"
#include <math.h>
#include <QString>

IXWindow::IXWindow(QQuickItem *parent) : QQuickItem(parent)
{

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
    _focusHandler = new IXWindowFocusHandler(parentItem());
    _focusHandler->stackAfter(this);
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
