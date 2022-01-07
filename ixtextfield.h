#ifndef IXTEXTFIELD_H
#define IXTEXTFIELD_H

#include <QQuickItem>

class IXTextField : public QQuickItem
{
    Q_OBJECT
public:
    IXTextField();
    void setTextValue(const QString&);

signals:
    void textUpdated(const QString& data);

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
