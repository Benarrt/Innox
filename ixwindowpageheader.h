#ifndef IXPAGEHEADER_H
#define IXPAGEHEADER_H

#include <QQuickItem>

#include "ixdynamiccomponent.h"

class IXWindowPageHeader : public IXDynamicComponent
{
    Q_OBJECT
public:
    IXWindowPageHeader();
signals:

protected:
    void componentComplete() override;
};

#endif // IXPAGEHEADER_H
