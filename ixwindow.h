#ifndef IXWINDOW_H
#define IXWINDOW_H

#include <QQuickItem>

//Resizes parent according to desired size and aspect ration based on actual size of window

class IXWindow : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(quint16 baseWidth MEMBER _baseWidth NOTIFY baseWidthChanged)
    Q_PROPERTY(quint16 baseHeight MEMBER _baseHeight NOTIFY baseHeightChanged)
public:
    IXWindow(QQuickItem *parent=nullptr);

    Q_INVOKABLE void setup(QQuickItem* parent, quint16 w = 720, quint16 h = 1280);

signals:
    void baseWidthChanged(quint16);
    void baseHeightChanged(quint16);

public slots:
    void windowResized();

protected:
    void componentComplete() override;

private:
    quint16 _baseWidth = 720;
    quint16 _baseHeight = 1280;
};

#endif // IXWINDOW_H
