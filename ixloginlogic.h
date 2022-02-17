#ifndef IXLOGINLOGIC_H
#define IXLOGINLOGIC_H

#include <functional>

#include "QString"

class IXLoginLogic
{
    using callbackT = std::function<void(const QString&)>;
public:
    IXLoginLogic(callbackT validLogin);

    void test(const QString&);

protected:

    callbackT _loginCallback;
};

#endif // IXLOGINLOGIC_H
