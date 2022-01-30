#include "ixstartupscreen.h"

IXStartupScreen::IXStartupScreen()
{

}

void IXStartupScreen::componentComplete()
{
    _logic.hideHeader();
    _logic.hideFooter();
    _logic.loadScreen("qrc:/QIXLoginScreen.qml");
}
