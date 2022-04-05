#ifndef IXWAREHOUSEPAGECATEGORYBRIDGE_H
#define IXWAREHOUSEPAGECATEGORYBRIDGE_H

#include <QQuickItem>
#include <vector>

class IXWarehousePageCategoryBridge : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QObject* listModel MEMBER _listModel NOTIFY listModelChanged)
public:
    IXWarehousePageCategoryBridge();

    Q_INVOKABLE void feedModel();

signals:
    void listModelChanged();

private:

    struct delegateData
    {
        int itemId;
    };

    struct META_METHODS
    {
        static constexpr char clear[] = "clear";
        static constexpr char pushBack[] = "pushBack";
    };

    static constexpr char DELEGATE_URL[] ="qrc:/QIXButton.qml";

protected:
    QObject* _listModel;
    std::vector<delegateData> _delegates;

};

#endif // IXWAREHOUSEPAGECATEGORYBRIDGE_H
