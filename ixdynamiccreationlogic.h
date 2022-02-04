#ifndef IXDYNAMICCREATIONLOGIC_H
#define IXDYNAMICCREATIONLOGIC_H
#include "functional"

#include <QQuickItem>

template<class T>
class IXDynamicCreationLogic
{
    using startFunctionT = std::function<void()>;
public:
    IXDynamicCreationLogic(T* object);

protected:
    virtual void dynamicReady() = 0;
};

#endif // IXDYNAMICCREATIONLOGIC_H
