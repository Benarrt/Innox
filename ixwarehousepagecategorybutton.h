#ifndef IXWAREHOUSEPAGECATEGORYBUTTON_H
#define IXWAREHOUSEPAGECATEGORYBUTTON_H

#include <QQuickItem>
#include "ixqcomponent.h"

class IXWarehousePageCategoryBridge;

class IXWarehousePageCategoryButton : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXWarehousePageCategoryButton();
    ~IXWarehousePageCategoryButton();

    Q_INVOKABLE void setup();

    void setText(const QString&);

signals:

protected:
    IXWarehousePageCategoryBridge* _bridge;
    uint32_t _itemId;

private:
    struct META_PROPERTIES
    {
        static constexpr char bridge[] = "bridge";
        static constexpr char text[] = "text";
        static constexpr char itemId[] = "itemId";
    };

};

#endif // IXWAREHOUSEPAGECATEGORYBUTTON_H
