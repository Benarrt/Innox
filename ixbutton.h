#ifndef IXBUTTON_H
#define IXBUTTON_H

#include <QQuickItem>

#include "ixqcomponent.h"

class IXButton : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT
public:
    IXButton(QQuickItem* parent = nullptr);

signals:

protected:
    void componentComplete() override;

private:
    struct META_PROPERTIES
    {
        static constexpr char hoverEnabled[] = "hoverEnabled";
    };
};

#endif // IXBUTTON_H
