#ifndef IXLOGINSCREEN_H
#define IXLOGINSCREEN_H

#include <QQuickItem>

#include "ixdynamiccreationlogic.h"
#include "ixscreenlogic.h"
#include "ixqcomponent.h"

class IXLoginScreen : public QQuickItem, public IXScreen
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXLoginScreen();

    const std::string headerURL() override;
    const std::string footerURL() override;

protected:
    void componentComplete() override;

private:
    class Logic :
            public IXDynamicCreationLogic<IXLoginScreen>,
            public IXScreenLogic
    {
    public:
        Logic(IXLoginScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(object),
            _component(object)
        {}

        void dynamicReady() override
        {
            qDebug("IXLoginScreen dynamicReady");
        }

    protected:
        IXLoginScreen* _component;
    };

    Logic _logic;

    friend class IXDynamicCreationLogic<IXLoginScreen>;
    friend class IXScreenLogic;
};

#endif // IXLOGINSCREEN_H
