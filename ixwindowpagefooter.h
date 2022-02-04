#ifndef IXWINDOWPAGEFOOTER_H
#define IXWINDOWPAGEFOOTER_H

#include <QQuickItem>
#include "ixdynamiccomponent.h"

//TODO Maybe crate common base class with load/hidefor IXWindowPageFooter and IXWindowPageHeader

class IXWindowPageFooter : public IXDynamicComponent
{
    Q_OBJECT
public:
    IXWindowPageFooter();

signals:

protected:
    void componentComplete() override;

private:
};

#endif // IXWINDOWPAGEFOOTER_H
