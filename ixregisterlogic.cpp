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

    if(data["registerStatus"] !=  QJsonValue::Undefined && data["registerStatus"].toBool())
    {
        _validRegisterCallback();
        return;
    }

    int erroCode = data["error"] == QJsonValue::Undefined ? 0 : data["error"].toInt();
    _invalidRegisterCallback(erroCode);
}

void IXRegisterLogic::registerAccount(const QString& username, const QString& password)
{
    IXBackendLess::inst().registerAccount(username, password, _registerStatusCallback);
}
