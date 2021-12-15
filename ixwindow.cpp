#include "ixwindow.h"
#include <math.h>
#include <QString>

IXWindow::IXWindow(QQuickItem *parent) : QQuickItem(parent)
{

}

void IXWindow::setup(QQuickItem* parent, quint16 w, quint16 h)
{
    connect(parent, &QQuickItem::widthChanged, this, &IXWindow::windowResized);
    connect(parent, &QQuickItem::heightChanged, this, &IXWindow::windowResized);
    _baseWidth = w;
    _baseHeight = h;
    this->setWidth(_baseWidth);
    this->setHeight(_baseHeight);
    windowResized();

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("verticalCenter", parent->property("verticalCenter"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("horizontalCenter", parent->property("horizontalCenter"));
}

void IXWindow::componentComplete()
{
    QQuickItem::componentComplete();
    if(parentItem())
        setup(parentItem(), 720, 1280);
    else
        qDebug("No parent item");
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
