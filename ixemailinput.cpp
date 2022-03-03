#include "ixemailinput.h"

IXEmailInput::IXEmailInput(QQuickItem* parent)
{

}

bool IXEmailInput::veryfiEmail()
{
    QString email = _component->property(META_PROPERTIES::text).toString();
    return _logic.isEmailValid(email);
}
