#ifndef IXDYNAMICDELEGATE_H
#define IXDYNAMICDELEGATE_H

#include <QQuickItem>
#include "ixdynamiccomponent.h"
#include "ixqcomponent.h"

class IXDynamicDelegate :  public IXDynamicComponent
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXDynamicDelegate();

signals:

protected:
    void componentComplete() override;

    Q_SLOT void onUrlChanged(const QUrl&) override;

    void fillComponent();

private:
};


#endif // IXDYNAMICDELEGATE_H
