#ifndef IXWINDOWTABHANDLER_H
#define IXWINDOWTABHANDLER_H

#include <QQuickItem>

class IXWindowTabHandler : public QQuickItem
{
    Q_OBJECT
public:
    static IXWindowTabHandler& inst()
    {
        static IXWindowTabHandler instance;
        return instance;
    }

    static const IXWindowTabHandler& cinst()
    {
        return IXWindowTabHandler::inst();
    }

    void tabEvent();

signals:

private:
    IXWindowTabHandler();
};

#endif // IXWINDOWTABHANDLER_H
