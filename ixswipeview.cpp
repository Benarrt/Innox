#include "ixswipeview.h"

IXSwipeView::IXSwipeView(QQuickItem* parent) : QQuickItem(parent), _component(nullptr)
{

}

IXSwipeView::~IXSwipeView()
{
    qDebug("~IXSwipeView");
}

void IXSwipeView::componentComplete()
{
    QQuickItem::componentComplete();
    qDebug("IXSwipeView::componentComplete");
    assert(parentItem());
    assert(parent());

    setParentItem(nullptr);
    //parentItem()->setObjectName("IXSwipeView");

    //QObject::connect(parent(), SIGNAL(currentIndexChanged()), this, SLOT(onCurrentIdexChanged()));
}

void IXSwipeView::onCurrentIdexChanged()
{
    qDebug("IXSwipeView");
    emit indexChanged(index());
}

qint16 IXSwipeView::index()
{
    return _component->property(META_PROPERTIES::currentIndex).toInt();
}

qint16 IXSwipeView::count()
{
    return _component->property(META_PROPERTIES::count).toInt();
}


