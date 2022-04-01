#include "ixwindowpageindexhandler.h"

IXWindowPageIndexHandler::IXWindowPageIndexHandler()
{

}

void IXWindowPageIndexHandler::addIndexObserver(IXPageIndicatorLogic* observer, callbackT callback)
{
    _indexObservers.insert(std::make_pair(observer, callback));
}
void IXWindowPageIndexHandler::addCountObserver(IXPageIndicatorLogic* observer, callbackT callback)
{
    _countObservers.insert(std::make_pair(observer, callback));
}

void IXWindowPageIndexHandler::removeIndexObserver(IXPageIndicatorLogic* observer)
{
    auto it = _indexObservers.find(observer);
    if(it != _indexObservers.end())
        _indexObservers.erase(it);
}

void IXWindowPageIndexHandler::removeCountObserver(IXPageIndicatorLogic* observer)
{
    auto it = _countObservers.find(observer);
    if(it != _countObservers.end())
        _countObservers.erase(it);
}

void IXWindowPageIndexHandler::notifyIndexObservers()
{
    for(auto observer : _indexObservers)
        observer.second(_pageIndex);
}

void IXWindowPageIndexHandler::notifyCountObservers()
{
    for(auto observer : _countObservers)
        observer.second(_pageCount);
}

void IXWindowPageIndexHandler::updatePageIndex(int index)
{
    if(_pageIndex == index)
        return;

    _pageIndex = index;
    notifyIndexObservers();
}

void IXWindowPageIndexHandler::updatePageCount(int count)
{
    if(_pageCount == count)
        return;

    _pageCount = count;
    notifyCountObservers();
}

int IXWindowPageIndexHandler::getPageIndex()
{
    return _pageIndex;
}
int IXWindowPageIndexHandler::getPageCount()
{
    return _pageCount;
}
