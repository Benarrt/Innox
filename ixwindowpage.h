#ifndef IXPAGE_H
#define IXPAGE_H

#include <QQuickItem>

#include "ixdynamiccomponent.h"
#include "ixqcomponent.h"

class IXWindowPage : public IXDynamicComponent
{
    Q_OBJECT
    //IX_Q_COMPONENT
public:
    IXWindowPage();
signals:

protected:
    void componentComplete() override;
};

#endif // IXPAGE_H
