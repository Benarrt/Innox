#ifndef IXDEALERSCREENHEADER_H
#define IXDEALERSCREENHEADER_H

#include <QQuickItem>
#include "ixdynamic.h"
#include "ixqcomponent.h"
#include "ixscreenlogic.h"
#include "ixloginlogic.h"
#include "ixdynamiccreationlogic.h"


class IXDealerScreenHeader : public QQuickItem, IXDynamic
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXDealerScreenHeader();

    Q_INVOKABLE void logOut();

    void onDynamicReady() override;

protected:
    void validLoginCallback();
    void invalidLoginCallback(uint16_t error);

private:
    class Logic :
            public IXDynamicCreationLogic,
            public IXScreenLogic,
            public IXLoginLogic
    {
    public:
        Logic(IXDealerScreenHeader* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(nullptr),
            IXLoginLogic(std::bind(&IXDealerScreenHeader::validLoginCallback, object),
                         std::bind(&IXDealerScreenHeader::invalidLoginCallback, object, std::placeholders::_1)),
            _component(object)
        {}

    protected:
        IXDealerScreenHeader* _component;
    };

    Logic _logic;

};

#endif // IXDEALERSCREENHEADER_H
