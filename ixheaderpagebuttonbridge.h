#ifndef IXHEADERPAGEBUTTONBRIDGE_H
#define IXHEADERPAGEBUTTONBRIDGE_H

#include <QQuickItem>

class IXHeaderPageButtonBridge : public QQuickItem
{
    Q_OBJECT
public:
    IXHeaderPageButtonBridge();

    Q_INVOKABLE void testFunction();

signals:

};

#endif // IXHEADERPAGEBUTTONBRIDGE_H
