#include "ixpageindicatorlogic.h"
#include "ixwindowpageindexhandler.h"
#include "ixpageindicatorobserver.h"

IXPageIndicatorLogic::IXPageIndicatorLogic(IXPageIndicatorObserver* observer)
{
    if(observer)
    {
        IXWindowPageIndexHandler::inst().addIndexObserver
                (this, std::bind(&IXPageIndicatorObserver::onPageIndexChanged, observer, std::placeholders::_1));

        IXWindowPageIndexHandler::inst().addCountObserver
                (this, std::bind(&IXPageIndicatorObserver::onPageCountChanged, observer, std::placeholders::_1));
    }
}

IXPageIndicatorLogic::~IXPageIndicatorLogic()
{
    IXWindowPageIndexHandler::inst().removeIndexObserver(this);
    IXWindowPageIndexHandler::inst().removeCountObserver(this);
}

void IXPageIndicatorLogic::updatePageIndex(int index)
{
    IXWindowPageIndexHandler::inst().updatePageIndex(index);
}

void IXPageIndicatorLogic::updatePageCount(int count)
{
    IXWindowPageIndexHandler::inst().updatePageCount(count);
}

int IXPageIndicatorLogic::pageIndex()
{
    return IXWindowPageIndexHandler::inst().getPageIndex();
}

int IXPageIndicatorLogic::pageCount()
{
    return IXWindowPageIndexHandler::inst().getPageCount();
}
