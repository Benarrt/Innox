#ifndef IXTEXTFIELD_H
#define IXTEXTFIELD_H

#include <QQuickItem>

class IXTextField : public QQuickItem
{
    Q_OBJECT
public:
    IXTextField();

    static IXTextField* inst;

signals:
    void setData(const QString& data);

protected:
    void componentComplete() override;

private:
    void onParentFocusChanged(bool);

    void focusInEvent(QFocusEvent *e) override;
    void focusOutEvent(QFocusEvent *e) override;

    void focusIn();
    void focusOut();


};

#endif // IXTEXTFIELD_H
