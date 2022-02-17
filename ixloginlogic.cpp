#include "ixloginlogic.h"
#include "ixbackendless.h"

IXLoginLogic::IXLoginLogic(callbackT loginCallback) :
    _loginCallback(loginCallback)
{
    IXBackendLess::inst().loginStatus(_loginCallback);
}

void IXLoginLogic::test(const QString& data)
{
    qDebug("IXLoginLogic::test");
    qDebug(data.toLocal8Bit());
}
