#include "ixwindowpage.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

#include <QString>

#include <QQuickWindow>

IXWindowPage::IXWindowPage() : _pageComponent(nullptr)
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPage::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    auto ixWindow = parent()->parent();

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

void IXWindowPage::setupDynamicComponent()
{
    _pageComponent = new IXDynamicComponent();
    _pageComponent->setup(parentItem(),parent());
}

void IXWindowPage::load(const QUrl& url)
{
    assert(url.isValid() && !url.isEmpty());
    if(_pageComponent)
        _pageComponent->setUrl(url);
}
