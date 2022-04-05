#include "ixwarehousepagecategorybridge.h"

IXWarehousePageCategoryBridge::IXWarehousePageCategoryBridge() : _listModel(nullptr)
{

}

Q_INVOKABLE void IXWarehousePageCategoryBridge::feedModel()
{
    QMetaObject::invokeMethod(_listModel, META_METHODS::clear);
    for(int i = 0; i < 150; i++)
    {
        QMetaObject::invokeMethod(_listModel, META_METHODS::pushBack,
                                  Q_ARG(QVariant, QVariant::fromValue(i)),
                                  Q_ARG(QVariant, QVariant::fromValue(QString(DELEGATE_URL))));
    }
}
