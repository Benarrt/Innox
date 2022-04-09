#ifndef IXWAREHOUSEPAGECATEGORYBRIDGE_H
#define IXWAREHOUSEPAGECATEGORYBRIDGE_H

#include <unordered_map>

#include <QQuickItem>

#include "ixwarehousecategorylogic.h"

class IXWarehousePageCategoryButton;

class IXWarehousePageCategoryBridge : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QObject* listModel MEMBER _listModel NOTIFY listModelChanged)
public:
    IXWarehousePageCategoryBridge();

    Q_INVOKABLE void feedModel();

    void setDelegateText(uint32_t);
    void registerDelegate(uint32_t _itemId, IXWarehousePageCategoryButton* item);
    void unregisterDelegate(uint32_t _itemId);

signals:
    void listModelChanged();

private:

    struct Logic : public IXWarehouseCategoryLogic
    {
    };

    struct DelegateData
    {
        uint32_t itemId;
        QString text;
    };

    struct META_METHODS
    {
        static constexpr char clear[] = "clear";
        static constexpr char pushBack[] = "pushBack";
    };

    static constexpr char DELEGATE_URL[] ="qrc:/QIXWarehousePageCategoryButton.qml"; //

protected:
    void fillModelWithCategories(const std::vector<uint32_t>&);

    Logic _logic;
    QObject* _listModel;
    std::unordered_map<uint32_t, DelegateData> _delegateCache;
    std::unordered_map<uint32_t, IXWarehousePageCategoryButton*> _delegates;

};

#endif // IXWAREHOUSEPAGECATEGORYBRIDGE_H
