#include "ixstartupscreen.h"

#include "QJsonDocument"

IXStartupScreen::IXStartupScreen() :
    _logic(this)
{

}

void IXStartupScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

void IXStartupScreen::validLoginCallback()
{
    qDebug("LOGIN IS VALID");
}
void IXStartupScreen::invalidLoginCallback()
{
    qDebug("LOGIN IS INVALID");
    _logic.loadLoginScreen();
}

const std::string IXStartupScreen::headerURL()
{
    return std::string("");
}

const std::string IXStartupScreen::footerURL()
{
    return std::string("");
}
