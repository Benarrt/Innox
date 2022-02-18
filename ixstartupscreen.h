#ifndef IXSTARTUPSCREEN_H
#define IXSTARTUPSCREEN_H

#include "ixscreenlogic.h"
#include "ixdynamiccreationlogic.h"
#include "ixqcomponent.h"
#include "ixloginlogic.h"

#include <QQuickItem>


class IXStartupScreen : public QQuickItem, public IXScreen
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXStartupScreen();

    const std::string headerURL() override;
    const std::string footerURL() override;

protected:
    static constexpr char HEADER_URL[] = "";
    static constexpr char FOOTER_URL[] = "";

    void componentComplete() override;

private:
    class Logic : public IXDynamicCreationLogic<IXStartupScreen>,
                  public IXScreenLogic,
                  public IXLoginLogic
    {
    public:
        Logic(IXStartupScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(object),
            IXLoginLogic(std::bind(&IXStartupScreen::validLoginCallback, object),
                         std::bind(&IXStartupScreen::invalidLoginCallback, object)),
            _component(object)
        {}

    protected:
        void dynamicReady() override
        {
            IXLoginLogic::loginStatus();
        }

        IXStartupScreen* _component;
    };

    void validLoginCallback();
    void invalidLoginCallback();

    friend class IXDynamicCreationLogic<IXStartupScreen>;
    friend class IXScreenLogic;

    Logic _logic;
};

#endif // IXSTARTUPSCREEN_H
