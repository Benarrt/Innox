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

void IXStartupScreen::onDynamicReady()
{
    _logic.loginStatus();
}

void IXStartupScreen::validLoginCallback()
{
    qDebug("LOGIN IS VALID");
    _logic.loadDealerScreen();
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
