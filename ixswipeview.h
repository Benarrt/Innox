#ifndef IXSWIPEVIEW_H
#define IXSWIPEVIEW_H

#include <QQuickItem>
#include "ixqcomponent.h"
#include "ixpageindicatorlogic.h"
#include "ixpageindicatorobserver.h"

class IXSwipeView : public QQuickItem, public IXPageIndicatorObserver
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXSwipeView(QQuickItem* parent = nullptr);

    void onPageIndexChanged(int) override;
    void onPageCountChanged(int) override;

protected slots:
    void onCurrentIndexChanged();
    void onCountChanged();

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
        static constexpr char count[] = "count";
    };

    void componentComplete() override;

private:
    class Logic : public IXPageIndicatorLogic
    {
        using IXPageIndicatorLogic::IXPageIndicatorLogic;
    };

    Logic _logic;
};

#endif // IXSWIPEVIEW_H
