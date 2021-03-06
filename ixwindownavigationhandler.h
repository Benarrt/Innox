#ifndef IXWINDOWNAVIGATIONHANDLER_H
#define IXWINDOWNAVIGATIONHANDLER_H

#include <QQuickItem>
class IXWindowNavigationHandler : public QQuickItem
{
    Q_OBJECT
public:
    static IXWindowNavigationHandler& inst()
    {
        static IXWindowNavigationHandler instance;
        return instance;
    }

    static IXWindowNavigationHandler& cinst()
    {
        return inst();
    }

    void goBack();

signals:
    void handleBack();

private:
    IXWindowNavigationHandler();
};

#endif // IXWINDOWNAVIGATIONHANDLER_H
