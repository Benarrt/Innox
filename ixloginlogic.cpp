#include "ixloginlogic.h"
#include "ixbackendless.h"

IXLoginLogic::IXLoginLogic(loginSatusEventT validLogin, loginSatusEventT invalidLogin) :
    _validLogin(validLogin),
    _invalidLogin(invalidLogin)
{
    IXBackendLess::inst().request<LOGIN_STATUS>(std::bind(&IXLoginLogic::test, this, std::placeholders::_1));
}

void IXLoginLogic::test(const QString& data)
{
    qDebug("IXLoginLogic::test");
    qDebug(data.toLocal8Bit());
}
