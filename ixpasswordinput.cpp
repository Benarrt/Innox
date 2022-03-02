#include "ixpasswordinput.h"

IXPasswordInput::IXPasswordInput(QQuickItem* parent) : IXTextField(parent)
{

}

QList<int> IXPasswordInput::veryfiPassword()
{
    QString password = _component->property(META_PROPERTIES::text).toString();
    auto errors = _logic.isPasswordValid(password);
    return QList<int>(errors.begin(), errors.end());
}
