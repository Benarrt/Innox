#ifndef IXPAGE_H
#define IXPAGE_H

#include <QQuickItem>

class IXDynamicComponent;

class IXWindowPage : public QQuickItem
{
    Q_OBJECT
public:
    IXWindowPage();

    Q_INVOKABLE void load(const QUrl& url);
signals:

protected:
    void componentComplete() override;

private:
   IXDynamicComponent* _pageComponent;

   void setupDynamicComponent();
};

#endif // IXPAGE_H
