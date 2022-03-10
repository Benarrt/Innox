#ifndef IXLOGINLOGIC_H
#define IXLOGINLOGIC_H

#include <functional>

#include "QString"

class IXLoginLogic
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

    innerCallbackT _loginStatusCallback;
    validCallbackT _validLoginCallback;
    invalidCallbackT _invalidLoginCallback;

    virtual void loginStatusCallback(const QString&);
};

#endif // IXLOGINLOGIC_H
