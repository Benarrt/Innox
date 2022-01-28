#include "ixscreenlogic.h"
#include "ixregistry.h"
#include "ixwindowpage.h"
#include "ixwindowpageheader.h"

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
