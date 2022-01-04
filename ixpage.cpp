#include "ixpage.h"
#include "QString"

IXPage::IXPage() : _item(nullptr)
{

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
}

void IXPage::loadPage(const QUrl& url)
{
    QQmlEngine *engine = qmlEngine(parent());
    // Or:
    // QQmlEngine *engine = qmlContext(this)->engine();
    QQmlComponent component(engine, url);
    qDebug(component.errorString().toLocal8Bit());
    if(_item)
    {
        delete _item;
        _item = nullptr;
    }
    QObject *myObject = component.create();
    qDebug(component.errorString().toLocal8Bit());
    _item = qobject_cast<QQuickItem*>(myObject);
    _item->setParentItem(parentItem());
}
