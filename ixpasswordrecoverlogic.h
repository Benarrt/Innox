#ifndef IXPASSWORDRECOVERLOGIC_H
#define IXPASSWORDRECOVERLOGIC_H

#include <functional>
#include "QString"

class IXPasswordRecoverLogic
{
    using callbackValidRecoverT = std::function<void()>;
    using callbackInvalidRecoverT = std::function<void(uint16_t)>;
    using innerCallbackT = std::function<void(const QString&)>;
public:
    IXPasswordRecoverLogic(callbackValidRecoverT validRecoverCallback, callbackInvalidRecoverT invalidRecoverCallback);

    void recoverAccountPassword(const QString& username);

protected:

    callbackValidRecoverT _validRecoverCallback;
    callbackInvalidRecoverT _invalidRecoverCallback;
    innerCallbackT _recoverStatusCallback;

    virtual void recoverStatusCallback(const QString&);
};

#endif // IXPASSWORDRECOVERLOGIC_H
