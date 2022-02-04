#include "ixwindowpage.h"
#include "ixdynamiccomponent.h"
#include "ixregistry.h"

#include <QString>

#include <QQuickWindow>

IXWindowPage::IXWindowPage()
{
    IXRegistry::inst().addToRegistry(this);
}

void IXWindowPage::componentComplete()
{
    QQuickItem::componentComplete();
    IXDynamicComponent::componentComplete();
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

}
