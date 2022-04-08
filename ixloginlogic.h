#ifndef IXLOGINLOGIC_H
#define IXLOGINLOGIC_H

#include "ixsafecallback.h"

#include "QString"

class IXLoginLogic : public IXSafeCallback
{
    using validCallbackT = std::function<void()>;
    using invalidCallbackT = std::function<void(uint16_t)>;
    using innerCallbackT = std::function<void(const QString&)>;
public:
    IXLoginLogic(validCallbackT validLoginCallback, invalidCallbackT invalidLoginCallback);

    void loginStatus();
    void logIn(const QString& username, const QString& password);
    void logOut();
protected:

    validCallbackT _validLoginCallback;
    invalidCallbackT _invalidLoginCallback;
    innerCallbackT _loginStatusCallback;

    virtual void loginStatusCallback(const QString&);
};

#endif // IXLOGINLOGIC_H
