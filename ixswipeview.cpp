#include "ixswipeview.h"

IXSwipeView::IXSwipeView(QQuickItem* parent) : QQuickItem(parent)
{
}

IXSwipeView::~IXSwipeView()
{
    qDebug("~IXSwipeView");
}

void IXSwipeView::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());
    assert(parent());

    setParentItem(nullptr);
    setObjectName("IXSwipeView");

    connect(component(), SIGNAL(currentIndexChanged()), this, SLOT(onCurrentIndexChanged()));
    onCurrentIndexChanged();
}

void IXSwipeView::onCurrentIndexChanged()
{
    _logic.upadtePageIndicator(component()->property(META_PROPERTIES::currentIndex).toInt(), component()->property(META_PROPERTIES::count).toInt());
}


