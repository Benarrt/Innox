#include "ixregistry.h"
#include "ixwindowpage.h"
#include "ixhandlebackpopup.h"
#include "ixwindow.h"
#include "ixwindowpageheader.h"

IXRegistry::IXRegistry() :
    _ixWindow(nullptr),
    _ixWindowPage(nullptr),
    _ixHandleBackPopup(nullptr),
    _ixWindowPageHeader(nullptr)
{

}

template <>
IXWindow* IXRegistry::get()
{
    return _ixWindow;
}

template <>
IXWindowPage* IXRegistry::get()
{
    return _ixWindowPage;
}

template <>
IXHandleBackPopup* IXRegistry::get()
{
    qDebug("IXHandleBackPopup");
    return _ixHandleBackPopup;
}

template <>
IXWindowPageHeader* IXRegistry::get()
{
    return _ixWindowPageHeader;
}

template <>
IXWindowPageFooter* IXRegistry::get()
{
    return _ixWindowPageFooter;
}

void IXRegistry::addToRegistry(IXWindow* ixWindow)
{
    _ixWindow= ixWindow;
}

void IXRegistry::addToRegistry(IXWindowPage* ixWindowPage)
{
    _ixWindowPage = ixWindowPage;
}

void IXRegistry::addToRegistry(IXHandleBackPopup* ixHandleBackPopup)
{
    _ixHandleBackPopup = ixHandleBackPopup;
}

void IXRegistry::addToRegistry(IXWindowPageHeader* ixWindowPageHeader)
{
    _ixWindowPageHeader = ixWindowPageHeader;
}

void IXRegistry::addToRegistry(IXWindowPageFooter* ixWindowPageFooter)
{
    _ixWindowPageFooter = ixWindowPageFooter;
}
