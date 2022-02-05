#ifndef IXHANDLEBACKPOPUP_H
#define IXHANDLEBACKPOPUP_H

#include <QQuickItem>

#include "ixqcomponent.h"

class IXHandleBackPopup : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXHandleBackPopup(QQuickItem* parent = nullptr);

    Q_INVOKABLE void goBack();
};

#endif // IXHANDLEBACKPOPUP_H
