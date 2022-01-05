#ifndef IXWINDOW_H
#define IXWINDOW_H

#include <QQuickItem>
#include <QQuickWindow>

//Resizes parent according to desired size and aspect ration based on actual size of window

class mouseEventHandler : public QQuickItem
{
    Q_OBJECT
public:
    mouseEventHandler(QQuickItem *parent=nullptr) : QQuickItem(parent)
    {
        qDebug("mouseEventHandler");
        setAcceptedMouseButtons(Qt::AllButtons);
        setAcceptTouchEvents(true);
        setFlag(ItemAcceptsInputMethod, true);
        connect(parent, &QQuickItem::widthChanged, this, &mouseEventHandler::windowResized);
        connect(parent, &QQuickItem::heightChanged, this, &mouseEventHandler::windowResized);
    }

signals:

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event) override
    {
        auto activeFocusItem = window()->activeFocusItem();
        if(activeFocusItem)
            activeFocusItem->setFocus(false);

        event->ignore();
    }

    virtual void touchEvent(QTouchEvent *event) override
    {
        auto activeFocusItem = window()->activeFocusItem();
        if(activeFocusItem)
            activeFocusItem->setFocus(false);

        event->ignore();
    }

private:

    void windowResized()
    {
        this->setWidth(this->parentItem()->width());
        this->setHeight(this->parentItem()->height());
    }

};

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

    mouseEventHandler* _mEHandler;
};

#endif // IXWINDOW_H
