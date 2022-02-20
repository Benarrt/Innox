#include "ixpasswordrecoverlogic.h"
#include "ixbackendless.h"
#include "QJsonDocument"

IXPasswordRecoverLogic::IXPasswordRecoverLogic(callbackValidRecoverT validRecoverCallback,
                                               callbackInvalidRecoverT invalidRecoverCallback) :
    _validRecoverCallback(validRecoverCallback),
    _invalidRecoverCallback(invalidRecoverCallback),
    _recoverStatusCallback(std::bind(&IXPasswordRecoverLogic::recoverStatusCallback, this, std::placeholders::_1))
{

}

void IXPasswordRecoverLogic::recoverStatusCallback(const QString& msg)
{
    auto data = QJsonDocument::fromJson(msg.toUtf8());

    if(data["error"] == QJsonValue::Undefined)
    {
        _validRecoverCallback();
        return;
    }

    _invalidRecoverCallback(data["error"].toInt());
}

void IXPasswordRecoverLogic::recoverAccountPassword(const QString& username)
{
    IXBackendLess::inst().recoverAccountPassword(username, _recoverStatusCallback);
}
