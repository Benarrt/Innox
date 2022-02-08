#ifndef IXWINDOWPAGEFOOTER_H
#define IXWINDOWPAGEFOOTER_H

#include <QQuickItem>
#include "ixdynamiccomponent.h"
#include "ixqcomponent.h"

//TODO Maybe crate common base class with load/hidefor IXWindowPageFooter and IXWindowPageHeader

class IXWindowPageFooter : public IXDynamicComponent
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXWindowPageFooter();

signals:

protected:
    void componentComplete() override;

    Q_SLOT void onUrlChanged(const QUrl&) override;

    void fillComponent();

private:
};

#endif // IXWINDOWPAGEFOOTER_H
