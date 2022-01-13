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
    void selectionChanged();

protected:
    void componentComplete() override;

private:
    void onParentFocusChanged(bool);

    void focusIn();
    void focusOut();
};

#endif // IXTEXTFIELD_H
