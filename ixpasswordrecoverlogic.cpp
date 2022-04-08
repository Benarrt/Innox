#include "ixpasswordrecoverlogic.h"
#include "ixbackendless.h"
#include "QJsonDocument"

IXPasswordRecoverLogic::IXPasswordRecoverLogic(callbackValidRecoverT validRecoverCallback,
                                               callbackInvalidRecoverT invalidRecoverCallback) :
    _validRecoverCallback(validRecoverCallback),
    _invalidRecoverCallback(invalidRecoverCallback)
{
    _recoverStatusCallback = safeCallback(&IXPasswordRecoverLogic::recoverStatusCallback);
}

void IXPasswordRecoverLogic::recoverStatusCallback(const QString& msg)
{
    auto data = QJsonDocument::fromJson(msg.toUtf8());

    if(data["status"] != QJsonValue::Undefined && data["status"].toBool())
    {
        _validRecoverCallback();
        return;
    }

    int erroCode = data["error"] == QJsonValue::Undefined ? 0 : data["error"].toInt();
    _invalidRecoverCallback(erroCode);
}

void IXPasswordRecoverLogic::recoverAccountPassword(const QString& username)
{
    IXBackendLess::inst().recoverAccountPassword(username, _recoverStatusCallback);
}
