#ifndef IXTEXTFIELD_H
#define IXTEXTFIELD_H

#include <QQuickItem>

class IXTextField : public QQuickItem
{
    Q_OBJECT
public:
    IXTextField();
    void setTextValue(quint16 cursorPos, const QString&);

signals:
    void textUpdated(quint16 cursorPos, const QString& data);

public slots:
    void cursorPositionChanged(quint16);

protected:
    void componentComplete() override;

private:
    void onParentFocusChanged(bool);

    void focusInEvent(QFocusEvent *e) override;
    void focusOutEvent(QFocusEvent *e) override;

    void focusIn();
    void focusOut();

    QString _textValue;
};

#endif // IXTEXTFIELD_H
