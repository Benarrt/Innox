#ifndef IXEMAILINPUT_H
#define IXEMAILINPUT_H

#include "ixtextfield.h"
#include "ixemaillogic.h"

class IXEmailInput : public IXTextField
{
    Q_OBJECT
public:
    IXEmailInput(QQuickItem* parent = nullptr);

    Q_INVOKABLE bool veryfiEmail();

private:

    struct Logic : public IXEmailLogic
    {

    };

    Logic _logic;
};

#endif // IXEMAILINPUT_H
