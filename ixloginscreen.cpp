#include "ixloginscreen.h"

IXLoginScreen::IXLoginScreen() : _logic(this)
{

}

void IXLoginScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

void IXLoginScreen::onDynamicReady()
{
    qDebug("IXLoginScreen test 1234");
}

const std::string IXLoginScreen::headerURL()
{
    return std::string("qrc:/QIXTestHeader.qml");
}

const std::string IXLoginScreen::footerURL()
{
    return std::string("qrc:/QIXPageIndicatorFooter.qml");
}

void IXLoginScreen::logIntoAccount(const QString& username, const QString& password)
{
    _logic.logIn(username, password);
}
