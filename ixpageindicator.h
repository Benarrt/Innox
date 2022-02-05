#ifndef IXPAGEINDICATOR_H
#define IXPAGEINDICATOR_H

#include <QQuickItem>

#include "ixqcomponent.h"

class IXPageIndicator : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXPageIndicator(QQuickItem* parent = nullptr);

    Q_INVOKABLE void setIndex(qint16 index);
    Q_INVOKABLE void setCount(qint16 count);

signals:

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
        static constexpr char count[] = "count";
    };

    void componentComplete() override;

};

#endif // IXPAGEINDICATOR_H
