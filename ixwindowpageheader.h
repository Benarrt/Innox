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

    Q_SLOT void onUrlChanged(const QUrl&) override;

    void fillComponent();
};

#endif // IXPAGEHEADER_H
