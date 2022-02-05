#ifndef IXDYNAMICCOMPONENT_H
#define IXDYNAMICCOMPONENT_H

#include <QQuickItem>
#include <QUrl>

#include "ixqcomponent.h"

class IXDynamicComponent : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
public:
    IXDynamicComponent();

    void setUrl(const QUrl& url);
    const QUrl& url();

    void setup(QQuickItem* parentItem, QObject* parent);

    QQuickItem* item();

signals:
    void urlChanged(QUrl);

public slots:
    void onUrlChanged(const QUrl&);

protected:
   bool changing;
   QQuickItem *_item;
   QUrl _url;

};

#endif // IXDYNAMICCOMPONENT_H
