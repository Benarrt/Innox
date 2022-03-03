#ifndef IXEMAILLOGIC_H
#define IXEMAILLOGIC_H

#include "QString"

class IXEmailLogic
{
public:
    IXEmailLogic();

    virtual bool isEmailValid(const QString& email);
};

#endif // IXEMAILLOGIC_H
