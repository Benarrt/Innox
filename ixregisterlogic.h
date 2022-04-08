#ifndef IXREGISTERLOGIC_H
#define IXREGISTERLOGIC_H

#include <functional>

#include <QString>

#include "ixsafecallback.h"

class IXRegisterLogic : public IXSafeCallback
{
    using callbackValidRegisterT = std::function<void()>;
    using callbackInvalidRegisterT = std::function<void(uint16_t)>;
    using innerCallbackT = std::function<void(const QString&)>;
public:
    IXRegisterLogic(callbackValidRegisterT validRegisterCallback, callbackInvalidRegisterT invalidRegisterCallback);

    void registerAccount(const QString& username, const QString& password);

protected:

    callbackValidRegisterT _validRegisterCallback;
    callbackInvalidRegisterT _invalidRegisterCallback;
    innerCallbackT _registerStatusCallback;

    virtual void registerStatusCallback(const QString&);
};

#endif // IXREGISTERLOGIC_H
