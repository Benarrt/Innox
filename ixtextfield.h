#ifndef IXTEXTFIELD_H
#define IXTEXTFIELD_H

#include <QQuickItem>

class IXTextField : public QQuickItem
{
    Q_OBJECT
public:
    IXTextField(QQuickItem* parent = nullptr);
    void setTextValue(const QString&);
    void setSelection(quint16 posBeg, quint16 posEnd);

public slots:
    void cursorPositionChanged();
    void selectionChanged();

protected:
    void componentComplete() override;
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void onParentFocusChanged(bool);

    void focusInEvent(QFocusEvent *e) override;
    void focusOutEvent(QFocusEvent *e) override;

    void focusIn();
    void focusOut();

    QString _textValue;
};

#endif // IXTEXTFIELD_H
