#ifndef IXLOGINLOGIC_H
#define IXLOGINLOGIC_H

#include <functional>

#include "QString"

class IXLoginLogic
{
    using callbackT = std::function<void()>;
public:
    IXLoginLogic(callbackT validLoginCallback, callbackT invalidLoginCallback);

    void loginStatus();
protected:

    callbackT _validLoginCallback;
    callbackT _invalidLoginCallback;

    virtual void loginStatusCallback(const QString&);
};

#endif // IXLOGINLOGIC_H
