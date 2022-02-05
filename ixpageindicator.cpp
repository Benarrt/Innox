#include "ixpageindicator.h"

IXPageIndicator::IXPageIndicator(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXPageIndicator::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());

    _component->setObjectName("IXPageIndicator");

}

void IXPageIndicator::setIndex(qint16 index)
{
    _component->setProperty(META_PROPERTIES::currentIndex, index);
}

void IXPageIndicator::setCount(qint16 count)
{
    _component->setProperty(META_PROPERTIES::count, count);
}
