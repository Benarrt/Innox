#include "ixwarehousepagecategorybridge.h"
#include "ixwarehousepagecategorybutton.h"

IXWarehousePageCategoryBridge::IXWarehousePageCategoryBridge() : _listModel(nullptr)
{

}

void IXWarehousePageCategoryBridge::feedModel()
{
    _logic.getChildCategories(0,
    std::bind(&IXWarehousePageCategoryBridge::fillModelWithCategories, this, std::placeholders::_1));
}

void IXWarehousePageCategoryBridge::fillModelWithCategories(const std::vector<uint32_t>& categoryIds)
{
    QMetaObject::invokeMethod(_listModel, META_METHODS::clear);
    for(auto id : categoryIds)
    {
        QMetaObject::invokeMethod(_listModel, META_METHODS::pushBack,
                                  Q_ARG(QVariant, QVariant::fromValue(id)),
                                  Q_ARG(QVariant, QVariant::fromValue(QString(DELEGATE_URL))));
    }
}

void IXWarehousePageCategoryBridge::setDelegateText(uint32_t itemId)
{
    IXWarehousePageCategoryButton* item;
    {
        auto it = _delegates.find(itemId);
        if(it == _delegates.end())
            return;

        item = it->second;
    }

    auto it = _delegateCache.find(itemId);
    if(it == _delegateCache.end())
    {
        _logic.getCategoryName(itemId, [this, itemId](const std::string& name)
        {
            _delegateCache.insert(std::make_pair(itemId, DelegateData
                                                 {
                                                   itemId,
                                                   QString::fromStdString(name)
                                                 }));
            setDelegateText(itemId);
        });
        return;
    }
    item->setText(it->second.text);
}

void IXWarehousePageCategoryBridge::registerDelegate(uint32_t itemId, IXWarehousePageCategoryButton* item)
{
    auto res = _delegates.insert(std::make_pair(itemId, item));
    setDelegateText(itemId);
}

void IXWarehousePageCategoryBridge::unregisterDelegate(uint32_t itemId)
{
    auto it = _delegates.find(itemId);
    _delegates.erase(it);
}
