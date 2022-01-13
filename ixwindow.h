#ifndef IXWINDOW_H
#define IXWINDOW_H

#include <QQuickItem>

//Resizes parent according to desired size and aspect ration based on actual size of window
//TODO make IXWindow just a hook for handlers like IXWindowFocusHandler move its current behaviour to some new handler

class IXWindow : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(quint16 baseWidth MEMBER _baseWidth NOTIFY baseWidthChanged)
    Q_PROPERTY(quint16 baseHeight MEMBER _baseHeight NOTIFY baseHeightChanged)
public:
    IXWindow(QQuickItem *parent=nullptr);

signals:
    void baseWidthChanged(quint16);
    void baseHeightChanged(quint16);

public slots:
    void windowResized();

protected:
    void componentComplete() override;
    bool childMouseEventFilter(QQuickItem *item, QEvent *event) override;

private:
    quint16 _baseWidth = 720;
    quint16 _baseHeight = 1280;

    void setup();
    void setupFocusHandler();
    void setupTabHandler();
};

#endif // IXWINDOW_H
