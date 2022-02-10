#ifndef IXDYNAMICCREATIONLOGIC_H
#define IXDYNAMICCREATIONLOGIC_H
#include "functional"

template<class T>
class IXDynamicCreationLogic
{
public:
    IXDynamicCreationLogic(T* object);

protected:
    virtual void dynamicReady() = 0;
};

#endif // IXDYNAMICCREATIONLOGIC_H
