#ifndef IXPASSWORDINPUT_H
#define IXPASSWORDINPUT_H

#include "ixtextfield.h"
#include "ixpasswordlogic.h"

class IXPasswordInput : public IXTextField
{
    Q_OBJECT
public:
    IXPasswordInput(QQuickItem* parent = nullptr);

    Q_INVOKABLE QList<int> veryfiPassword();

private:

    struct Logic : public IXPasswordLogic
    {

    };

    Logic _logic;
};

#endif // IXPASSWORDINPUT_H
