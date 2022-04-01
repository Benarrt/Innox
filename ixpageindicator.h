#ifndef IXPAGEINDICATOR_H
#define IXPAGEINDICATOR_H

#include <QQuickItem>
#include "ixpageindicatorlogic.h"
#include "ixqcomponent.h"
#include "ixpageindicatorobserver.h"

class IXPageIndicator : public QQuickItem, IXPageIndicatorObserver
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXPageIndicator(QQuickItem* parent = nullptr);

    Q_SLOT void onPageIndexChanged(int) override;
    Q_SLOT void onPageCountChanged(int) override;

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
        static constexpr char count[] = "count";
    };

    void componentComplete() override;

private:
    struct Logic : public IXPageIndicatorLogic
    {
        using IXPageIndicatorLogic::IXPageIndicatorLogic;
    };

    Logic _logic;

};

#endif // IXPAGEINDICATOR_H
