#ifndef IXPAGEHEADER_H
#define IXPAGEHEADER_H

#include <QQuickItem>

class IXDynamicComponent;

class IXWindowPageHeader : public QQuickItem
{
    Q_OBJECT
public:
    IXWindowPageHeader();

    Q_INVOKABLE void load(const QUrl& url);
    Q_INVOKABLE void hide();

signals:

protected:
    void componentComplete() override;

private:
    void setupDynamicComponent();

    IXDynamicComponent* _headerComponent;

};

#endif // IXPAGEHEADER_H
