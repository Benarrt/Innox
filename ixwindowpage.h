#ifndef IXPAGE_H
#define IXPAGE_H

#include <QQuickItem>

#include "ixdynamiccomponent.h"
#include "ixqcomponent.h"

class IXWindowPage : public IXDynamicComponent
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXWindowPage();
signals:

protected:
    void componentComplete() override;
    Q_SLOT void updatePageWidth();
};

#endif // IXPAGE_H
