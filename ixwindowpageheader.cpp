#include "ixwindowpageheader.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

IXWindowPageHeader::IXWindowPageHeader()
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPageHeader::componentComplete()
{
    QQuickItem::componentComplete();
    IXDynamicComponent::componentComplete();
    assert(parent());
    assert(parentItem());
}
