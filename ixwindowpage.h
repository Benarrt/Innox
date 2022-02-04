#ifndef IXPAGE_H
#define IXPAGE_H

#include <QQuickItem>

#include "ixdynamiccomponent.h"

class IXWindowPage : public IXDynamicComponent
{
    Q_OBJECT
public:
    IXWindowPage();
signals:

protected:
    void componentComplete() override;
};

#endif // IXPAGE_H
