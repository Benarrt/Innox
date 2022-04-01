#include "ixswipeview.h"

IXSwipeView::IXSwipeView(QQuickItem* parent) : QQuickItem(parent), _logic(this)
{
}

void IXSwipeView::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());
    assert(parent());

    setParentItem(nullptr);
    setObjectName("IXSwipeView");

    connect(component(), SIGNAL(currentIndexChanged()), this, SLOT(onCurrentIndexChanged()));
    connect(component(), SIGNAL(countChanged()), this, SLOT(onCountChanged()));
    onCurrentIndexChanged();
    onCountChanged();
}

void IXSwipeView::onCurrentIndexChanged()
{
    _logic.updatePageIndex(component()->property(META_PROPERTIES::currentIndex).toInt());
}

void IXSwipeView::onCountChanged()
{
    _logic.updatePageCount(component()->property(META_PROPERTIES::count).toInt());
}

void IXSwipeView::onPageIndexChanged(int index)
{
    component()->setProperty(META_PROPERTIES::currentIndex, index);
}

void IXSwipeView::onPageCountChanged(int count)
{
    component()->setProperty(META_PROPERTIES::count, count);
}
