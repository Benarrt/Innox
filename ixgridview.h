#ifndef IXGRIDVIEW_H
#define IXGRIDVIEW_H

#include "qquickitem.h"
#include "ixqcomponent.h"

class IXGridView : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT

    Q_PROPERTY(QQuickItem* gridView MEMBER _gridView NOTIFY gridViewChanged)
public:
    explicit IXGridView(QQuickItem *parent = nullptr);

    Q_INVOKABLE void setup();

protected:
    void componentComplete() override;

    Q_SLOT void calculateOptimalWidth();

    QQuickItem* _gridView;
    int _optimalWidth;

signals:
    void gridViewChanged();

private:
    struct META_PROPERTIES
    {
        static constexpr char width[] = "width";
        static constexpr char model[] = "model";
        static constexpr char count[] = "count";
        static constexpr char cellWidth[] = "cellWidth";
        static constexpr char itemSpacingW[] = "itemSpacingW";
        static constexpr char maxColumns[] = "maxColumns";
    };
};

#endif // IXGRIDVIEW_H
