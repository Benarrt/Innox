#ifndef IXSWIPEVIEW_H
#define IXSWIPEVIEW_H

#include <QQuickItem>
#include "ixqcomponent.h"

class IXSwipeView : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXSwipeView(QQuickItem* parent = nullptr);
    ~IXSwipeView();

    Q_INVOKABLE qint16 index();
    Q_INVOKABLE qint16 count();

signals:
    void indexChanged(qint16 index);

protected slots:
    void onCurrentIdexChanged();

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
        static constexpr char count[] = "count";
    };

    void componentComplete() override;
};

#endif // IXSWIPEVIEW_H
