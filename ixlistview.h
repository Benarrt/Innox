#ifndef IXLISTVIEW_H
#define IXLISTVIEW_H

#include <QQuickItem>
#include "ixqcomponent.h"

class IXListView : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT

    Q_PROPERTY(QQuickItem* listView MEMBER _listView NOTIFY listViewChanged)
public:
    IXListView(QQuickItem *parent = nullptr);

    Q_INVOKABLE void setup();

protected:
    Q_SLOT void calculateOptimalWidth();

    QQuickItem* _listView;
    int _optimalWidth;

signals:
    void listViewChanged();

private:
    struct META_PROPERTIES
    {
        static constexpr char width[] = "width";
        static constexpr char model[] = "model";
        static constexpr char count[] = "count";
        static constexpr char itemW[] = "itemW";
        static constexpr char itemSpacingW[] = "itemSpacingW";
        static constexpr char interactive[] = "interactive";
    };

};

#endif // IXLISTVIEW_H
