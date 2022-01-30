#include "ixloginscreen.h"

IXLoginScreen::IXLoginScreen()
{

}

void IXLoginScreen::componentComplete()
{
    _logic.loadHeader("qrc:/QIXTestHeader.qml");
}
