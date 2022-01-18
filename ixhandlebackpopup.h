#ifndef IXHANDLEBACKPOPUP_H
#define IXHANDLEBACKPOPUP_H

#include <QQuickItem>

class IXHandleBackPopup : public QQuickItem
{
    Q_OBJECT
public:
    IXHandleBackPopup(QQuickItem* parent = nullptr);

    Q_INVOKABLE void goBack();

signals:

};

#endif // IXHANDLEBACKPOPUP_H
