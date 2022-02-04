#include "ixdynamiccomponent.h"

IXDynamicComponent::IXDynamicComponent() : _item(nullptr), changing(false)
{
    connect(this, &IXDynamicComponent::urlChanged, this, &IXDynamicComponent::onUrlChanged);
}

void IXDynamicComponent::setup(QQuickItem* parentItem, QObject* parent)
{
    setParentItem(parentItem);
    setParent(parent);
}

QQuickItem* IXDynamicComponent::item()
{
    return _item;
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
    assert(!changing);
    changing = true;
    qDebug(url.toString().toLocal8Bit());

    if(_item != nullptr)
    {
        _item->deleteLater();
        _item = nullptr;
    }

    if(url.isEmpty() || !url.isValid())
    {
        parentItem()->setVisible(false);
        return;
    }
    parentItem()->setVisible(true);

    QQmlEngine *engine = qmlEngine(parent());
    // Or:
    // QQmlEngine *engine = qmlContext(this)->engine();
    QQmlComponent component(engine, url);
    qDebug(component.errorString().toLocal8Bit());
    QVariantMap qvm;
    qvm["enabled"] = QVariant(false);
    QObject *myObject = component.createWithInitialProperties(qvm);
    qDebug(component.errorString().toLocal8Bit());
    _item = qobject_cast<QQuickItem*>(myObject);
    _item->setParentItem(parentItem());
    changing = false;
    _item->setEnabled(true);
}
