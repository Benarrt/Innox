#include "ixdynamiccomponent.h"
#include "ixdynamic.h"

IXDynamicComponent::IXDynamicComponent() : _item(nullptr), changing(false)
{
    connect(this, &IXDynamicComponent::urlChanged, this, &IXDynamicComponent::onUrlChanged);
}

IXDynamicComponent::~IXDynamicComponent()
{
    if(_item)
        delete _item;
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
    ScopeGuard doneChaning([this] { changing = false;});
    changing = true;
    //qDebug(url.toString().toLocal8Bit());

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
    auto error = component.errorString().toLocal8Bit();
    if(!error.isEmpty())
        qDebug(component.errorString().toLocal8Bit());
    QObject *myObject = component.create();
    error = component.errorString().toLocal8Bit();
    if(!error.isEmpty())
        qDebug(component.errorString().toLocal8Bit());
    _item = qobject_cast<QQuickItem*>(myObject);
    _item->setParentItem(this);
    _item->setParent(this);

    IXDynamic* itemLogic = nullptr;
    if(_item->property("logic").isValid())
    {
        itemLogic = dynamic_cast<IXDynamic*>(_item->property("logic").value<QQuickItem*>());
    }

    //Not so pretty side cast
    if(!itemLogic)
        return;

    itemLogic->onDynamicReady();
}
