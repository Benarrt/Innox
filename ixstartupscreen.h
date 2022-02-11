#ifndef IXSTARTUPSCREEN_H
#define IXSTARTUPSCREEN_H

#include "ixscreenlogic.h"
#include "ixdynamiccreationlogic.h"
#include "ixqcomponent.h"
#include "ixloginlogic.h"

#include <QQuickItem>


class IXStartupScreen : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXStartupScreen();

protected:
    static constexpr char HEADER_URL[] = "";
    static constexpr char FOOTER_URL[] = "";

    void componentComplete() override;

    virtual void onValidLogin();
    virtual void onInvalidLogin();

private:
    class Logic : public IXDynamicCreationLogic<IXStartupScreen>,
                  public IXScreenLogic<IXStartupScreen>,
                  public IXLoginLogic
    {
    public:
        Logic(IXStartupScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(),
            IXLoginLogic([](){}, [](){}),
            _component(object)
        {}

    protected:
        void dynamicReady() override
        {
            IXScreenLogic::load();
        }

        IXStartupScreen* _component;
    };

    friend class IXDynamicCreationLogic<IXStartupScreen>;
    friend class IXScreenLogic<IXStartupScreen>;

    Logic _logic;
};

#endif // IXSTARTUPSCREEN_H
