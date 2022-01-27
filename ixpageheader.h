#ifndef IXPAGEHEADER_H
#define IXPAGEHEADER_H

#include <QQuickItem>

class IXDynamicComponent;

class IXPageHeader : public QQuickItem
{
    Q_OBJECT
public:
    IXPageHeader();

    Q_INVOKABLE void load(const QUrl& url);
signals:

protected:
    void componentComplete() override;

private:
    void setupDynamicComponent();

    IXDynamicComponent* _headerComponent;

};

#endif // IXPAGEHEADER_H
