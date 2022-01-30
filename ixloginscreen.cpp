#include "ixloginscreen.h"

IXLoginScreen::IXLoginScreen()
{

}

void IXLoginScreen::componentComplete()
{
    _logic.loadHeader("qrc:/QIXTestHeader.qml");
    _logic.loadFooter("qrc:/QIXPageIndicatorFooter.qml");
}
