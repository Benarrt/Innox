#include "ixwindowpageheader.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

IXWindowPageHeader::IXWindowPageHeader() : _headerComponent(nullptr)
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPageHeader::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());
    assert(parentItem());

    setupDynamicComponent();
}

void IXWindowPageHeader::setupDynamicComponent()
{
    _headerComponent = new IXDynamicComponent();
    _headerComponent->setup(parentItem(),parent());
}

void IXWindowPageHeader::load(const QUrl& url)
{
    _headerComponent->setUrl(url);
    parentItem()->setVisible(true);
}

void IXWindowPageHeader::hide()
{
    _headerComponent->setUrl(QUrl());
    parentItem()->setVisible(false);
}
