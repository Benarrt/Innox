#ifndef IXLOGINLOGIC_H
#define IXLOGINLOGIC_H

#include <functional>

#include "QString"

class IXLoginLogic
{
    using callbackT = std::function<void()>;
    using innerCallbackT = std::function<void(const QString&)>;
public:
    IXLoginLogic(callbackT validLoginCallback, callbackT invalidLoginCallback);

    void loginStatus();
    void logIn(const QString& username, const QString& password);
    void logOut();
protected:

    innerCallbackT _loginStatusCallback;
    callbackT _validLoginCallback;
    callbackT _invalidLoginCallback;

    virtual void loginStatusCallback(const QString&);
};

#endif // IXLOGINLOGIC_H
