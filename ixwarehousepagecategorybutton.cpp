#include "ixwarehousepagecategorybutton.h"
#include "ixwarehousepagecategorybridge.h"

IXWarehousePageCategoryButton::IXWarehousePageCategoryButton() : _bridge(nullptr), _itemId(0)
{

}

IXWarehousePageCategoryButton::~IXWarehousePageCategoryButton()
{
    if(_bridge)
        _bridge->unregisterDelegate(_itemId);
}

void IXWarehousePageCategoryButton::setup()
{
    if(_bridge)
        _bridge->unregisterDelegate(_itemId);

    _bridge = reinterpret_cast<IXWarehousePageCategoryBridge*>
            (_component->property(META_PROPERTIES::bridge).value<QQuickItem*>());
    _itemId = _component->property(META_PROPERTIES::itemId).toInt();
    _bridge->registerDelegate(_itemId, this);
}

void IXWarehousePageCategoryButton::setText(const QString& text)
{
    _component->setProperty(META_PROPERTIES::text, text);
}
