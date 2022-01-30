#include "ixscreenlogic.h"
#include "ixregistry.h"
#include "ixwindowpage.h"
#include "ixwindowpageheader.h"
#include "ixwindowpagefooter.h"

IXScreenLogic::IXScreenLogic()
{

}

void IXScreenLogic::loadScreen(const std::string& url)
{
    auto windowPage = IXRegistry::inst().get<IXWindowPage>();
    if(windowPage)
        windowPage->load(QString::fromStdString(url));
}

void IXScreenLogic::loadHeader(const std::string& url)
{
    auto windowPageHeader = IXRegistry::inst().get<IXWindowPageHeader>();
    if(windowPageHeader)
        windowPageHeader->load(QString::fromStdString(url));
}

void IXScreenLogic::hideHeader()
{
    auto windowPageHeader = IXRegistry::inst().get<IXWindowPageHeader>();
    if(windowPageHeader)
        windowPageHeader->hide();
}

void IXScreenLogic::loadFooter(const std::string& url)
{
    auto windowPageFooter = IXRegistry::inst().get<IXWindowPageFooter>();
    if(windowPageFooter)
        windowPageFooter->load(QString::fromStdString(url));
}

void IXScreenLogic::hideFooter()
{
    auto windowPageFooter = IXRegistry::inst().get<IXWindowPageFooter>();
    if(windowPageFooter)
        windowPageFooter->hide();
}
