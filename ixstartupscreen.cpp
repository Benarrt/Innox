#include "ixstartupscreen.h"

IXStartupScreen::IXStartupScreen() :
    _logic(this)
{

}

void IXStartupScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

void IXStartupScreen::onValidLogin()
{
    qDebug("onValidLogin");
}

void IXStartupScreen::onInvalidLogin()
{
    _logic.loadScreen("qrc:/QIXLoginScreen");
}
