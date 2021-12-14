#include "ixwindow.h"
#include <math.h>
#include <QString>

IXWindow::IXWindow(QQuickItem *parent) : QQuickItem(parent)
{

}

void IXWindow::setup(QQuickItem* parent, quint16 w, quint16 h)
{
    setParentItem(parent);
    connect(parent, &QQuickItem::widthChanged, this, &IXWindow::windowResized);
    connect(parent, &QQuickItem::heightChanged, this, &IXWindow::windowResized);
    _width = w;
    _height = h;
    this->setWidth(_width);
    this->setHeight(_height);
    windowResized();

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("verticalCenter", parent->property("verticalCenter"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("horizontalCenter", parent->property("horizontalCenter"));
}

void IXWindow::windowResized()
{
    qreal scaleW = 1.0f;
    qreal scaleH = 1.0f;
    qreal appliedScale = 1.0f;

    qreal parentWidth = parentItem()->width();
    qreal parentHeight = parentItem()->height();

    if(parentWidth < this->_width) {
        scaleW = parentWidth / this->_width;
    }

    if(parentHeight < this->_height) {
        scaleH = parentHeight / this->_height;
    }
    appliedScale = fmin(scaleW, scaleH);
    this->setWidth(parentWidth / appliedScale);
    this->setHeight(parentHeight / appliedScale);
    this->setScale(appliedScale);
}
