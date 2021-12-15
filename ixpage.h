#ifndef IXPAGE_H
#define IXPAGE_H

#include <QQuickItem>

class IXPage : public QQuickItem
{
    Q_OBJECT
public:
    IXPage();

    Q_INVOKABLE void loadPage(const QUrl& url);

signals:

protected:
    void componentComplete() override;

private:
   QQuickItem* _item;
};

#endif // IXPAGE_H
