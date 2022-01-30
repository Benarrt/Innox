#ifndef IXSTARTUPSCREEN_H
#define IXSTARTUPSCREEN_H

#include "ixscreenlogic.h"

#include <QQuickItem>


class IXStartupScreen : public QQuickItem
{
    Q_OBJECT
public:
    IXStartupScreen();

protected:
    void componentComplete() override;

private:
    class Logic : public IXScreenLogic
    {};

    Logic _logic;
};

#endif // IXSTARTUPSCREEN_H
