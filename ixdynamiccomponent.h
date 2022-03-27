#ifndef IXDYNAMICCOMPONENT_H
#define IXDYNAMICCOMPONENT_H

#include <QQuickItem>
#include <QUrl>

#include "ixqcomponent.h"

class IXDynamicComponent : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
public:
    IXDynamicComponent();

    void setUrl(const QUrl& url);
    const QUrl& url();

    void setup(QQuickItem* parentItem, QObject* parent);

    Q_INVOKABLE QQuickItem* item();

signals:
    void urlChanged(QUrl);

public slots:
    virtual void onUrlChanged(const QUrl&);

protected:
   bool changing;
   QQuickItem *_item;
   QUrl _url;

private:
   class ScopeGuard
   {
        public:
            ScopeGuard(std::function<void()> exec) : _exec(exec) {}
            ~ScopeGuard() { _exec(); }

            ScopeGuard(const ScopeGuard&) = delete;
            ScopeGuard(const ScopeGuard&&) noexcept = delete;
            ScopeGuard& operator=(const ScopeGuard&) = delete;
            ScopeGuard& operator=(const ScopeGuard&&) noexcept = delete;

        private:
            std::function<void()> _exec;
   };

};

#endif // IXDYNAMICCOMPONENT_H
