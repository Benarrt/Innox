#ifndef IXQCOMPONENT_H
#define IXQCOMPONENT_H

#define IX_Q_COMPONENT Q_PROPERTY(QQuickItem* component READ component WRITE setComponent NOTIFY componentChanged) \
                       public: \
                       Q_INVOKABLE QQuickItem* component() \
                       { \
                           return _component; \
                       } \
                       Q_INVOKABLE void setComponent(QQuickItem* component) \
                       { \
                           _component = component; \
                           _component->setProperty("logic", QVariant::fromValue(qobject_cast<QQuickItem*>(this))); \
                           emit componentChanged(_component); \
                       } \
                       Q_SIGNAL void componentChanged(QQuickItem* item=nullptr); \
                       protected: \
                           QQuickItem* _component;
#endif // IXQCOMPONENT_H
