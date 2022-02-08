#ifndef IXLOGINSCREEN_H
#define IXLOGINSCREEN_H

#include "ixdynamiccreationlogic.h"
#include "ixscreenlogic.h"
#include "ixpageindicatorlogic.h"

#include <QQuickItem>
#include "ixqcomponent.h"

class IXLoginScreen : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXLoginScreen();

    Q_INVOKABLE void changeScreenTest();

    ~IXLoginScreen()
    {
        qDebug("IXLoginScreen destructor");
    }

protected:
    static constexpr char HEADER_URL[] = "qrc:/QIXTestHeader.qml";
    static constexpr char FOOTER_URL[] = "qrc:/QIXPageIndicatorFooter.qml";

    void componentComplete() override;

private:
    class Logic :
            public IXDynamicCreationLogic<IXLoginScreen>,
            public IXScreenLogic<IXLoginScreen>,
            public IXPageIndicatorLogic
    {
    public:
        Logic(IXLoginScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(),
            IXPageIndicatorLogic(),
            _component(object)
        {}

        void dynamicReady() override
        {

        }

    protected:
        IXLoginScreen* _component;
    };

    Logic _logic;

    friend class IXDynamicCreationLogic<IXLoginScreen>;
    friend class IXScreenLogic<IXLoginScreen>;
};

#endif // IXLOGINSCREEN_H
