#include "ixwindowpagefooter.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"


IXWindowPageFooter::IXWindowPageFooter()
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPageFooter::componentComplete()
{
    QQuickItem::componentComplete();
    IXDynamicComponent::componentComplete();

    assert(parent());
    assert(parentItem());
}
