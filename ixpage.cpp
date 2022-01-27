#include "ixpage.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

#include <QString>

IXPage::IXPage() : _pageComponent(nullptr)
{
    IXRegistry::inst().addToRegistry(this);
}

void IXPage::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    auto ixWindow = parent()->parent();
    auto ixWindow2 = QQuickItem::window();

    quint16 baseWidth = ixWindow->property("baseWidth").toUInt();
    quint16 baseHeight = ixWindow->property("baseHeight").toUInt();

    parent()->setProperty("width", baseWidth);
    parent()->setProperty("height", baseHeight);
    parent()->setProperty("clip", true);

    qvariant_cast<QObject*>(parent()->property("anchors"))->
            setProperty("horizontalCenter", ixWindow->property("horizontalCenter"));

    qvariant_cast<QObject*>(parent()->property("anchors"))->
            setProperty("top", ixWindow->property("top"));


    setupDynamicComponent();
}

void IXPage::setupDynamicComponent()
{
    _pageComponent = new IXDynamicComponent();
    _pageComponent->setup(parentItem(),parent());
}

void IXPage::load(const QUrl& url)
{
    if(_pageComponent)
        _pageComponent->setUrl(url);
}
