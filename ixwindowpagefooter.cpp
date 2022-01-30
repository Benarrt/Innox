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
    assert(parent());
    assert(parentItem());

    parentItem()->setHeight(100);

    setupDynamicComponent();
}

void IXWindowPageFooter::setupDynamicComponent()
{
    _footerComponent = new IXDynamicComponent();
    _footerComponent->setup(parentItem(),parent());
}

void IXWindowPageFooter::load(const QUrl& url)
{
    _footerComponent->setUrl(url);
    parentItem()->setVisible(true);
}

void IXWindowPageFooter::hide()
{
    _footerComponent->setUrl(QUrl());
    parentItem()->setVisible(false);
}
