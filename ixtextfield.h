#ifndef IXTEXTFIELD_H
#define IXTEXTFIELD_H

#include <QQuickItem>
#include "ixqcomponent.h"

class IXTextField : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXTextField(QQuickItem* parent = nullptr);
    void setTextValue(const QString&);
    void setSelection(quint16 posBeg, quint16 posEnd);

public slots:
    void selectionChanged();

protected:
    void componentComplete() override;

    struct META_PROPERTIES
    {
        static constexpr char selectionStart[] = "selectionStart";
        static constexpr char selectionEnd[] = "selectionEnd";
        static constexpr char cursorPosition[] = "cursorPosition";
        static constexpr char text[] = "text";
        static constexpr char selectByMouse[] = "selectByMouse";
    };

    struct META_METHODS
    {
        static constexpr char select[] = "select";
    };

    void onParentFocusChanged(bool);

    void focusIn();
    void focusOut();
};

#endif // IXTEXTFIELD_H
