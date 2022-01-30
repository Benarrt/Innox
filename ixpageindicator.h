#ifndef IXPAGEINDICATOR_H
#define IXPAGEINDICATOR_H

#include <QQuickItem>

class IXPageIndicator : public QQuickItem
{
    Q_OBJECT
public:
    IXPageIndicator(QQuickItem* parent = nullptr);

    Q_INVOKABLE void setIndex(qint16 index);
signals:

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
    };

    void componentComplete() override;

};

#endif // IXPAGEINDICATOR_H
