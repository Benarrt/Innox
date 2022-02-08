#include "ixloginscreen.h"

IXLoginScreen::IXLoginScreen() : _logic(this)
{

}

void IXLoginScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

void IXLoginScreen::changeScreenTest()
{
    _logic.loadScreen("qrc:/QIXStartupScreen.qml");
}
