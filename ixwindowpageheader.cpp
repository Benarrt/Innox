#include "ixwindowpageheader.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

IXWindowPageHeader::IXWindowPageHeader()
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPageHeader::componentComplete()
{
    assert(parent());
    assert(parentItem());

    QQuickItem::componentComplete();
    IXDynamicComponent::componentComplete();

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("top", parent()->property("top"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("bottom", parent()->property("bottom"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("left", parent()->property("left"));

    qvariant_cast<QObject*>(
        this->property("anchors")
    )->setProperty("right", parent()->property("right"));
}

void IXWindowPageHeader::onUrlChanged(const QUrl& url)
{
    IXDynamicComponent::onUrlChanged(url);
    fillComponent();
}

void IXWindowPageHeader::fillComponent()
{
    _component->setHeight(_item->height());
    qvariant_cast<QObject*>(
        _item->property("anchors")
    )->setProperty("top", this->property("top"));

    qvariant_cast<QObject*>(
        _item->property("anchors")
    )->setProperty("bottom", this->property("bottom"));

    qvariant_cast<QObject*>(
        _item->property("anchors")
    )->setProperty("left", this->property("left"));

    qvariant_cast<QObject*>(
        _item->property("anchors")
    )->setProperty("right", this->property("right"));
}
