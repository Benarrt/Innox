#ifndef IXPAGE_H
#define IXPAGE_H

#include <QQuickItem>

class IXDynamicComponent;

class IXPage : public QQuickItem
{
    Q_OBJECT
public:
    IXPage();

    Q_INVOKABLE void load(const QUrl& url);
signals:

protected:
    void componentComplete() override;

private:
   IXDynamicComponent* _pageComponent;

   void setupDynamicComponent();
};

#endif // IXPAGE_H
