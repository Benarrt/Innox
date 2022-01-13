#ifndef IXWINDOWFOCUSHANDLER_H
#define IXWINDOWFOCUSHANDLER_H

#include <QQuickItem>

//This class catches clicks on empty undefinded space

class IXWindowFocusHandler : public QQuickItem
{
    Q_OBJECT
public:
    static IXWindowFocusHandler& inst()
    {
        static IXWindowFocusHandler instance;
        return instance;
    }

    static IXWindowFocusHandler& cinst()
    {
        return IXWindowFocusHandler::inst();
    }

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    IXWindowFocusHandler(QQuickItem *parent=nullptr);
    void onParentChanged(QQuickItem*);
    void windowResized();
};

#endif // IXWINDOWFOCUSHANDLER_H
