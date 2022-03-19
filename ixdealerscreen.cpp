#include "ixdealerscreen.h"

IXDealerScreen::IXDealerScreen() : _logic(this)
{

}

void IXDealerScreen::componentComplete()
{
    QQuickItem::componentComplete();
}

void IXDealerScreen::onDynamicReady()
{
    qDebug("IXDealerScreen test 1234");
}

const std::string IXDealerScreen::headerURL()
{
    return std::string("qrc:/QIXDealerScreenHeader.qml");
}

const std::string IXDealerScreen::footerURL()
{
    return std::string("");//std::string("qrc:/QIXPageIndicatorFooter.qml");
}
