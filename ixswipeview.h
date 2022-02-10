#ifndef IXSWIPEVIEW_H
#define IXSWIPEVIEW_H

#include <QQuickItem>
#include "ixqcomponent.h"
#include "ixpageindicatorlogic.h"

class IXSwipeView : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXSwipeView(QQuickItem* parent = nullptr);
    ~IXSwipeView();

protected slots:
    void onCurrentIndexChanged();

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
        static constexpr char count[] = "count";
    };

    void componentComplete() override;

private:
    class Logic : public IXPageIndicatorLogic
    { };

    Logic _logic;
};

#endif // IXSWIPEVIEW_H
