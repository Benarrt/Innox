#ifndef IXDYNAMICCOMPONENT_H
#define IXDYNAMICCOMPONENT_H

#include <QQuickItem>
#include <QUrl>

class IXDynamicComponent : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
public:
    IXDynamicComponent();

    void setUrl(const QUrl& url);
    const QUrl& url();

    void setup(QQuickItem* parentItem, QObject* parent);

signals:
    void urlChanged(QUrl);

public slots:
    void onUrlChanged(const QUrl&);

private:
   QQuickItem *_item;
   QUrl _url;

};

#endif // IXDYNAMICCOMPONENT_H
