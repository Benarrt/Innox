#ifndef IXLOGINSCREEN_H
#define IXLOGINSCREEN_H

#include "ixscreenlogic.h"

#include <QQuickItem>

class IXLoginScreen : public QQuickItem
{
    Q_OBJECT
public:
    IXLoginScreen();

protected:
    void componentComplete() override;

private:
    class Logic : public IXScreenLogic
    {};

    Logic _logic;


};

#endif // IXLOGINSCREEN_H
