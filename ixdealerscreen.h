#ifndef IXDEALERSCREEN_H
#define IXDEALERSCREEN_H

#include <QQuickItem>

#include "ixdynamiccreationlogic.h"
#include "ixscreenlogic.h"
#include "ixqcomponent.h"
#include "ixloginlogic.h"
#include "ixregisterlogic.h"
#include "ixdynamic.h"
#include "ixpasswordrecoverlogic.h"

class IXDealerScreen : public QQuickItem, public IXScreen, public IXDynamic
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXDealerScreen();

    const std::string headerURL() override;
    const std::string footerURL() override;

    void onDynamicReady() override;

signals:

protected:
    void componentComplete() override;
private:
    class Logic :
            public IXDynamicCreationLogic,
            public IXScreenLogic
    {
    public:
        Logic(IXDealerScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(object),
            _component(object)
        {}

    protected:
        IXDealerScreen* _component;
    };

    Logic _logic;
};

#endif // IXDEALERSCREEN_H
