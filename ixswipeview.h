#ifndef IXSWIPEVIEW_H
#define IXSWIPEVIEW_H

#include <QQuickItem>

class IXSwipeView : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQuickItem* component READ component WRITE setComponent NOTIFY componentChanged)
public:
    IXSwipeView(QQuickItem* parent = nullptr);
    ~IXSwipeView();

    Q_INVOKABLE qint16 index();
    Q_INVOKABLE qint16 count();

    Q_INVOKABLE QQuickItem* component()
    {
        return _component;
    }

    Q_INVOKABLE void setComponent(QQuickItem* component)
    {
        qDebug("setting component");
        _component = component;
    }

signals:
    void indexChanged(qint16 index);
    void componentChanged(QQuickItem*);

protected slots:
    void onCurrentIdexChanged();

protected:
    struct META_PROPERTIES
    {
        static constexpr char currentIndex[] = "currentIndex";
        static constexpr char count[] = "count";
    };

    void componentComplete() override;

    QQuickItem* _component;
};

#endif // IXSWIPEVIEW_H
