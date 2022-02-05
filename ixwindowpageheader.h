#ifndef IXPAGEHEADER_H
#define IXPAGEHEADER_H

#include <QQuickItem>

#include "ixdynamiccomponent.h"
#include "ixqcomponent.h"

class IXWindowPageHeader : public IXDynamicComponent
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXWindowPageHeader();
signals:

protected:
    void componentComplete() override;
};

#endif // IXPAGEHEADER_H
