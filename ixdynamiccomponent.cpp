#include "ixdynamiccomponent.h"

IXDynamicComponent::IXDynamicComponent() : _item(nullptr)
{
    connect(this, &IXDynamicComponent::urlChanged, this, &IXDynamicComponent::onUrlChanged);
}

void IXDynamicComponent::setup(QQuickItem* parentItem, QObject* parent)
{
    setParentItem(parentItem);
    setParent(parent);
}

void IXDynamicComponent::setUrl(const QUrl& url)
{
    if(_url == url)
        return;

    _url = url;
    emit urlChanged(_url);
}

const QUrl& IXDynamicComponent::url()
{
    return _url;
}

void IXDynamicComponent::onUrlChanged(const QUrl& url)
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
    _item->setParent(parent());
}
