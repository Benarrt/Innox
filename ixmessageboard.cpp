#include "ixmessageboard.h"
#include <QJsonObject>
#include <QVariant>


IXMessageBoard::IXMessageBoard()
{

}

void IXMessageBoard::componentComplete()
{
    QQuickItem::componentComplete();
    assert(parent());
    assert(parentItem());

    clear();
}

void IXMessageBoard::clear()
{
    msgList.clear();
    QMetaObject::invokeMethod(qvariant_cast<QObject*>(_component->property(META_PROPERTIES::model)), META_METHODS::clear);
    _component->parentItem()->setProperty("desiredHeight", 0);
}

void IXMessageBoard::addMessage(int msgID)
{
    msgList.push_back(msgID);
    QMetaObject::invokeMethod(_component->property(META_PROPERTIES::model).value<QObject*>(),
                              META_METHODS::pushBack, Q_ARG(QVariant, QVariant::fromValue(msgID)));


    int desiredHeight = _component->parentItem()->property("contentHeight").toInt() * msgList.size();
    _component->parentItem()->setProperty("desiredHeight", desiredHeight);
}

void IXMessageBoard::addMessages(const QList<int>& msgIDs)
{
    for(const auto msgID : msgIDs)
    {
        msgList.push_back(msgID);
        QMetaObject::invokeMethod(_component->property(META_PROPERTIES::model).value<QObject*>(),
                                  META_METHODS::pushBack, Q_ARG(QVariant, QVariant::fromValue(msgID)));
    }

    int desiredHeight = _component->parentItem()->property("contentHeight").toInt() * msgList.size();
    _component->parentItem()->setProperty("desiredHeight", desiredHeight);
}
