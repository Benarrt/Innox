#include "ixloginlogic.h"
#include "ixbackendless.h"

#include "QJsonDocument"

IXLoginLogic::IXLoginLogic(callbackT validLoginCallback, callbackT invalidLoginCallback) :
    _validLoginCallback(validLoginCallback), _invalidLoginCallback(invalidLoginCallback)
{

}

void IXLoginLogic::loginStatus()
{
    IXBackendLess::inst().loginStatus(std::bind(&IXLoginLogic::loginStatusCallback, this, std::placeholders::_1));
}

void IXLoginLogic::loginStatusCallback(const QString& msg)
{
    qDebug("loginCallback");
    auto data = QJsonDocument::fromJson(msg.toUtf8());

    if(data["loginStatus"] == QJsonValue::Undefined ||
            !data["loginStatus"].toBool())
    {
        _invalidLoginCallback();
        return;
    }

    _validLoginCallback();
}
