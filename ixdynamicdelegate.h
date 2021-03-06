#ifndef IXDYNAMICDELEGATE_H
#define IXDYNAMICDELEGATE_H

#include <QQuickItem>
#include "ixdynamiccomponent.h"
#include "ixqcomponent.h"

class IXDynamicDelegate :  public IXDynamicComponent
{
    Q_OBJECT
    IX_Q_COMPONENT

    Q_PROPERTY(QQuickItem* bridge MEMBER _bridge NOTIFY bridgeChanged)
    Q_PROPERTY(int itemId MEMBER _itemId NOTIFY itemIdChanged)
public:
    IXDynamicDelegate();

signals:
    void bridgeChanged();
    void itemIdChanged();

protected:
    void componentComplete() override;

    void fillComponent();

    Q_SLOT void onUrlChanged(const QUrl&) override;

    QQuickItem* _bridge;
    int _itemId;

private:

    struct META_PROPERTIES
    {
        static constexpr char width[] = "width";
        static constexpr char height[] = "height";
    };
};


#endif // IXDYNAMICDELEGATE_H
