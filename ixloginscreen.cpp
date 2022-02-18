#include "ixloginscreen.h"

IXLoginScreen::IXLoginScreen() : _logic(this)
{

}

void IXLoginScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

const std::string IXLoginScreen::headerURL()
{
    return std::string("qrc:/QIXTestHeader.qml");
}

const std::string IXLoginScreen::footerURL()
{
    return std::string("qrc:/QIXPageIndicatorFooter.qml");
}
