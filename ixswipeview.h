#ifndef IXSWIPEVIEW_H
#define IXSWIPEVIEW_H

#include <QQuickItem>

class IXSwipeView : public QQuickItem
{
    Q_OBJECT
public:
    IXSwipeView(QQuickItem* parent = nullptr);

//signals:
    void currentIndexChanged();

protected:
    void componentComplete() override;

private:

};

#endif // IXSWIPEVIEW_H
