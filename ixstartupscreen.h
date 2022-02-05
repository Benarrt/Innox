#ifndef IXSTARTUPSCREEN_H
#define IXSTARTUPSCREEN_H

#include "ixscreenlogic.h"
#include "ixdynamiccreationlogic.h"
#include "ixqcomponent.h"

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

private:
    class Logic : public IXDynamicCreationLogic<IXStartupScreen>,
                  public IXScreenLogic<IXStartupScreen>
    {
    public:
        Logic(IXStartupScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(),
            _component(object)
        {}

    protected:
        void dynamicReady() override
        {
            qDebug("dynamicReady");
            IXScreenLogic::load();
            IXScreenLogic::loadScreen("qrc:/QIXLoginScreen.qml");
        }

        IXStartupScreen* _component;
    };

    friend class IXDynamicCreationLogic<IXStartupScreen>;
    friend class IXScreenLogic<IXStartupScreen>;

    Logic _logic;
};

#endif // IXSTARTUPSCREEN_H
