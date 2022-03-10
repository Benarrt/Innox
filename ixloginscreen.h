#ifndef IXLOGINSCREEN_H
#define IXLOGINSCREEN_H

#include <QQuickItem>

#include "ixdynamiccreationlogic.h"
#include "ixscreenlogic.h"
#include "ixqcomponent.h"
#include "ixloginlogic.h"
#include "ixregisterlogic.h"
#include "ixdynamic.h"
#include "ixpasswordrecoverlogic.h"

class IXLoginScreen : public QQuickItem, public IXScreen, public IXDynamic
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXLoginScreen();

    const std::string headerURL() override;
    const std::string footerURL() override;

    Q_INVOKABLE void logIntoAccount(const QString& username, const QString& password);
    Q_INVOKABLE void registerAccount(const QString& username, const QString& password);
    Q_INVOKABLE void recoverAccountPassword(const QString& username);

    void onDynamicReady() override;

signals:
    void validRegister();
    void invalidRegister(int error);

    void validLogin();
    void invalidLogin(int error);

    void validPWRecover();
    void invalidPWRecover(int error);


protected:
    void componentComplete() override;

    void validLoginCallback();
    void invalidLoginCallback(uint16_t error);
    void validRegisterCallback();
    void invalidRegisterCallback(uint16_t error);
    void validRecoverCallback();
    void invalidRecoverCallback(uint16_t error);

private:
    class Logic :
            public IXDynamicCreationLogic,
            public IXScreenLogic,
            public IXLoginLogic,
            public IXRegisterLogic,
            public IXPasswordRecoverLogic
    {
    public:
        Logic(IXLoginScreen* object) :
            IXDynamicCreationLogic(object),
            IXScreenLogic(object),
            IXLoginLogic(std::bind(&IXLoginScreen::validLoginCallback, object),
                         std::bind(&IXLoginScreen::invalidLoginCallback, object, std::placeholders::_1)),
            IXRegisterLogic(std::bind(&IXLoginScreen::validRegisterCallback, object),
                            std::bind(&IXLoginScreen::invalidRegisterCallback, object, std::placeholders::_1)),
            IXPasswordRecoverLogic(std::bind(&IXLoginScreen::validRecoverCallback, object),
                                   std::bind(&IXLoginScreen::invalidRecoverCallback, object, std::placeholders::_1)),
            _component(object)
        {}

    protected:
        IXLoginScreen* _component;
    };

    Logic _logic;
};

#endif // IXLOGINSCREEN_H
