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

void IXLoginScreen::registerAccount(const QString& username, const QString& password)
{
    _logic.registerAccount(username, password);
}

void IXLoginScreen::recoverAccountPassword(const QString& username)
{
    _logic.recoverAccountPassword(username);
}

void IXLoginScreen::validLoginCallback()
{
    qDebug("LOGINC SUCCES");
}
void IXLoginScreen::invalidLoginCallback()
{
    qDebug("LOGINC FAIL");
}
void IXLoginScreen::validRegisterCallback()
{
    qDebug("REGISTER SUCCES");
}
void IXLoginScreen::invalidRegisterCallback(uint16_t error)
{
    qDebug("REGISTER FAIL");
    qDebug(QString::number(error).toLocal8Bit());
}

void IXLoginScreen::validRecoverCallback()
{
    qDebug("RECOVER SUCCES");
}

void IXLoginScreen::invalidRecoverCallback(uint16_t error)
{
    qDebug("RECOVER FAIL");
    qDebug(QString::number(error).toLocal8Bit());
}

