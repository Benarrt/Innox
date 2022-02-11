#ifndef IXLOGINSCREEN_H
#define IXLOGINSCREEN_H

#include <QQuickItem>

#include "ixdynamiccreationlogic.h"
#include "ixscreenlogic.h"
#include "ixqcomponent.h"

class IXLoginScreen : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXLoginScreen();

protected:
    static constexpr char HEADER_URL[] = "qrc:/QIXTestHeader.qml";
    static constexpr char FOOTER_URL[] = "qrc:/QIXPageIndicatorFooter.qml";

    void componentComplete() override;

private:
    class Logic :
            public IXDynamicCreationLogic<IXLoginScreen>,
            public IXScreenLogic<IXLoginScreen>
    {
    public:
        Logic(IXLoginScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(),
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
    friend class IXScreenLogic<IXLoginScreen>;
};

#endif // IXLOGINSCREEN_H
