#include "ixdynamicdelegate.h"

IXDynamicDelegate::IXDynamicDelegate()
{

}


void IXDynamicDelegate::componentComplete()
{
    assert(parent());
    assert(parentItem());

    QQuickItem::componentComplete();
}

void IXDynamicDelegate::onUrlChanged(const QUrl& url)
{
    IXDynamicComponent::onUrlChanged(url);
    if(_item != nullptr)
        fillComponent();
}

void IXDynamicDelegate::fillComponent()
{
    _item->setProperty("width", 200);
    _item->setProperty("height", 200);
}
