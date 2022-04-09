#include "ixwindowpage.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

#include <QString>
#include <QQuickWindow>

#include "ixregistry.h"
#include "ixwindow.h"

IXWindowPage::IXWindowPage()
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPage::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());

    auto ixWindow = IXRegistry::inst().get<IXWindow>();

    quint16 baseWidth = ixWindow->property("baseWidth").toUInt();
    quint16 baseHeight = ixWindow->property("baseHeight").toUInt();

    _component->setProperty("width", baseWidth);
    _component->setProperty("height", baseHeight);
    _component->setProperty("clip", true);

    connect(ixWindow, SIGNAL(widthChanged()), this, SLOT(updatePageWidth()));

    qvariant_cast<QObject*>(_component->property("anchors"))->
            setProperty("horizontalCenter", ixWindow->property("horizontalCenter"));

    qvariant_cast<QObject*>(_component->property("anchors"))->
            setProperty("top", ixWindow->property("top"));

}

void IXWindowPage::onUrlChanged(const QUrl& url)
{
    IXDynamicComponent::onUrlChanged(url);
    if(_item)
    {
        this->setHeight(_item->height());
        this->setWidth(_item->width());
    }
}

void IXWindowPage::updatePageWidth()
{
    auto ixWindow = IXRegistry::inst().get<IXWindow>();
    _component->setProperty("width", ixWindow->property("width").toUInt());
}
