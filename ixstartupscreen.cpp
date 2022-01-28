#include "ixstartupscreen.h"

IXStartupScreen::IXStartupScreen()
{

}

void IXStartupScreen::componentComplete()
{
    _logic.loadScreen("qrc:/QIXLoginScreen.qml");
}
