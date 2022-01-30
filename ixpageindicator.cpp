#include "ixpageindicator.h"

IXPageIndicator::IXPageIndicator(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXPageIndicator::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());

    parentItem()->setObjectName("IXPageIndicator");

}

void IXPageIndicator::setIndex(qint16 index)
{
    parentItem()->setProperty(META_PROPERTIES::currentIndex, index);
}
