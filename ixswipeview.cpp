#include "ixswipeview.h"

IXSwipeView::IXSwipeView(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXSwipeView::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parentItem());

    parentItem()->setObjectName("IXSwipeView");

    QObject::connect(parentItem(), SIGNAL(currentIndexChanged()), this, SLOT(currentIndexChanged()));
}

void IXSwipeView::currentIndexChanged()
{
    qDebug("IXSwipeView");
}

