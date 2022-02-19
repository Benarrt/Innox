#include "ixregisterlogic.h"
#include "ixbackendless.h"

#include "QJsonDocument"

IXRegisterLogic::IXRegisterLogic(callbackValidRegisterT validRegisterCallback, callbackInvalidRegisterT invalidRegisterCallback) :
    _validRegisterCallback(validRegisterCallback),
    _invalidRegisterCallback(invalidRegisterCallback),
    _registerStatusCallback(std::bind(&IXRegisterLogic::registerStatusCallback, this, std::placeholders::_1))
{

}

void IXRegisterLogic::registerStatusCallback(const QString& msg)
{
    auto data = QJsonDocument::fromJson(msg.toUtf8());

    if(data["error"] == QJsonValue::Undefined)
    {
        _validRegisterCallback();
        return;
    }

    _invalidRegisterCallback(data["error"].toInt());
}

void IXRegisterLogic::registerAccount(const QString& username, const QString& password)
{
    IXBackendLess::inst().registerAccount(username, password, _registerStatusCallback);
}
