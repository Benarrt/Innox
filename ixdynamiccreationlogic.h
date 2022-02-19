#ifndef IXDYNAMICCREATIONLOGIC_H
#define IXDYNAMICCREATIONLOGIC_H
#include "functional"

class IXDynamic;

//This class does nothing so far beside ensuring that owner of this logic is deriving from IXDynamic

class IXDynamicCreationLogic
{
public:
    IXDynamicCreationLogic(IXDynamic* object);
};

#endif // IXDYNAMICCREATIONLOGIC_H
