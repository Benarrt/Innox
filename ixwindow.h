#ifndef IXWINDOW_H
#define IXWINDOW_H

#include <QQuickItem>
//Resizes parent according to desired size and aspect ration based on actual size of window

class IXWindow : public QQuickItem
{
    Q_OBJECT
public:
    IXWindow(QQuickItem *parent=nullptr);

    Q_INVOKABLE void setup(QQuickItem* parent, quint16 w = 720, quint16 h = 1280);

public slots:
    void onParentChanged() { qDebug("Parent changed"); };

public slots:
    void windowResized();

protected:
    void componentComplete() override;

private:
    quint16 _width = 720;
    quint16 _height = 1280;
};

#endif // IXWINDOW_H
