#ifndef IXWINDOWPAGEFOOTER_H
#define IXWINDOWPAGEFOOTER_H

#include <QQuickItem>

class IXDynamicComponent;

//TODO Maybe crate common base class with load/hidefor IXWindowPageFooter and IXWindowPageHeader

class IXWindowPageFooter : public QQuickItem
{
    Q_OBJECT
public:
    IXWindowPageFooter();

    Q_INVOKABLE void load(const QUrl& url);
    Q_INVOKABLE void hide();

signals:

protected:
    void componentComplete() override;

private:
    void setupDynamicComponent();

    IXDynamicComponent* _footerComponent;

};

#endif // IXWINDOWPAGEFOOTER_H
