#include "ixpageindicator.h"

IXPageIndicator::IXPageIndicator(QQuickItem* parent) : QQuickItem(parent), _logic(this)
{

}

void IXPageIndicator::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());

    onPageCountChanged(_logic.pageCount());
    onPageIndexChanged(_logic.pageIndex());
}

void IXPageIndicator::onPageIndexChanged(int index)
{
    _component->setProperty(META_PROPERTIES::currentIndex, index);
}

void IXPageIndicator::onPageCountChanged(int count)
{
    _component->setProperty(META_PROPERTIES::count, count);
}
