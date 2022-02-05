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
                           qDebug("setting component"); \
                           _component = component; \
                           emit componentChanged(_component); \
                       } \
                       Q_SIGNAL void componentChanged(QQuickItem* item=nullptr); \
                       protected: \
                           QQuickItem* _component;
#endif // IXQCOMPONENT_H
