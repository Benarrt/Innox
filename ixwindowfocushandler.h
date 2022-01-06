#ifndef IXWINDOWFOCUSHANDLER_H
#define IXWINDOWFOCUSHANDLER_H

#include <QQuickItem>

//This class resets focus after everylick inside application
//So even if we click nonfocusable item, the one with focus will lose it

class IXWindowFocusHandler : public QQuickItem
{
    Q_OBJECT
public:
    IXWindowFocusHandler(QQuickItem *parent=nullptr);

signals:

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void touchEvent(QTouchEvent *event) override;
private:

    void windowResized();
};

#endif // IXWINDOWFOCUSHANDLER_H
