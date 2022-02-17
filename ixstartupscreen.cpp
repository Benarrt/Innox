#include "ixstartupscreen.h"

IXStartupScreen::IXStartupScreen() :
    _logic(this)
{

}

void IXStartupScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

void IXStartupScreen::loginCallback(const QString& data)
{
    qDebug("loginCallback");
    qDebug(data.toLocal8Bit());
}
