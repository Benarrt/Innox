#include "ixregistry.h"
#include "ixpage.h"
#include "ixhandlebackpopup.h"
#include "ixwindow.h"
#include "ixpageheader.h"

IXRegistry::IXRegistry() :
    _ixWindow(nullptr),
    _ixPage(nullptr),
    _ixHandleBackPopup(nullptr),
    _ixPageHeader(nullptr)
{

}

template <>
IXWindow* IXRegistry::get()
{
    return _ixWindow;
}

template <>
IXPage* IXRegistry::get()
{
    return _ixPage;
}

template <>
IXHandleBackPopup* IXRegistry::get()
{
    qDebug("IXHandleBackPopup");
    return _ixHandleBackPopup;
}

template <>
IXPageHeader* IXRegistry::get()
{
    return _ixPageHeader;
}

void IXRegistry::addToRegistry(IXWindow* ixWindow)
{
    _ixWindow= ixWindow;
}

void IXRegistry::addToRegistry(IXPage* ixPage)
{
    _ixPage = ixPage;
}

void IXRegistry::addToRegistry(IXHandleBackPopup* ixHandleBackPopup)
{
    _ixHandleBackPopup = ixHandleBackPopup;
}

void IXRegistry::addToRegistry(IXPageHeader* ixPageHeader)
{
    _ixPageHeader = ixPageHeader;
}
