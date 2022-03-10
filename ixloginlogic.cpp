#include "ixloginlogic.h"
#include "ixbackendless.h"

#include "QJsonDocument"

IXLoginLogic::IXLoginLogic(validCallbackT validLoginCallback, invalidCallbackT invalidLoginCallback) :
    _loginStatusCallback(std::bind(&IXLoginLogic::loginStatusCallback, this, std::placeholders::_1)),
    _validLoginCallback(validLoginCallback),
    _invalidLoginCallback(invalidLoginCallback)
{

}

void IXLoginLogic::loginStatus()
{
    IXBackendLess::inst().loginStatus(_loginStatusCallback);
}

void IXLoginLogic::logIn(const QString& username, const QString& password)
{
    IXBackendLess::inst().logIn(username, password, _loginStatusCallback);
}

void IXLoginLogic::logOut()
{
    IXBackendLess::inst().logOut(_loginStatusCallback);
}

void IXLoginLogic::loginStatusCallback(const QString& msg)
{
    qDebug("loginCallback");
    auto data = QJsonDocument::fromJson(msg.toUtf8());

    if(data["status"] != QJsonValue::Undefined &&
            data["status"].toBool())
    {
        _validLoginCallback();
        return;
    }

    int erroCode = data["error"] == QJsonValue::Undefined ? 0 : data["error"].toInt();
    _invalidLoginCallback(erroCode);
}
