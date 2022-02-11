#ifndef IXLOGINLOGIC_H
#define IXLOGINLOGIC_H

#include <functional>

#include "QString"

class IXLoginLogic
{
    using loginSatusEventT = std::function<void()>;
public:
    IXLoginLogic(loginSatusEventT validLogin, loginSatusEventT invalidLogin);

    void test(const QString&);

protected:

    loginSatusEventT _validLogin;
    loginSatusEventT _invalidLogin;
};

#endif // IXLOGINLOGIC_H
