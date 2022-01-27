#include "ixpageheader.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

IXPageHeader::IXPageHeader() : _headerComponent(nullptr)
{
    IXRegistry::inst().addToRegistry(this);
}

void IXPageHeader::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    setupDynamicComponent();
}

void IXPageHeader::setupDynamicComponent()
{
    _headerComponent = new IXDynamicComponent();
    _headerComponent->setup(parentItem(),parent());
}

void IXPageHeader::load(const QUrl& url)
{
    _headerComponent->setUrl(url);
}
