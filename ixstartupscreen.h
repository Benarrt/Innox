#ifndef IXSTARTUPSCREEN_H
#define IXSTARTUPSCREEN_H

#include "ixscreenlogic.h"
#include "ixdynamiccreationlogic.h"
#include "ixqcomponent.h"
#include "ixloginlogic.h"
#include "ixdynamic.h"

#include <QQuickItem>


class IXStartupScreen : public QQuickItem, public IXScreen, public IXDynamic
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXStartupScreen();

    const std::string headerURL() override;
    const std::string footerURL() override;

    void onDynamicReady() override;

protected:
    static constexpr char HEADER_URL[] = "";
    static constexpr char FOOTER_URL[] = "";

    void componentComplete() override;

private:
    class Logic : public IXDynamicCreationLogic,
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
        IXStartupScreen* _component;
    };

    void validLoginCallback();
    void invalidLoginCallback();

    Logic _logic;
};

#endif // IXSTARTUPSCREEN_H
