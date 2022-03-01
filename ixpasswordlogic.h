#ifndef IXPASSWORDLOGIC_H
#define IXPASSWORDLOGIC_H

#include "QString"
#include "QList"

class IXPasswordLogic
{
public:
    IXPasswordLogic();

    virtual QList<int> isPasswordValid(const QString& password);
};

#endif // IXPASSWORDLOGIC_H
