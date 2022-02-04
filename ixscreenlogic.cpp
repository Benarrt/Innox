#include "ixscreenlogic.h"
#include "ixregistry.h"
#include "ixwindowpage.h"
#include "ixwindowpageheader.h"
#include "ixwindowpagefooter.h"
#include "ixstartupscreen.h"
#include "ixloginscreen.h"

template<class T>
IXScreenLogic<T>::IXScreenLogic()
{
    load();
}

template<class T>
void IXScreenLogic<T>::loadComponent(IXDynamicComponent* comp, const std::string& url)
{
    if(comp)
        comp->setUrl(QString::fromStdString(url));
}

template<class T>
void IXScreenLogic<T>::load()
{
    loadHeader(T::HEADER_URL);
    loadFooter(T::FOOTER_URL);
}

template<class T>
void IXScreenLogic<T>::loadScreen(const std::string& url)
{
    loadComponent(IXRegistry::inst().get<IXWindowPage>(), url);
}

template<class T>
void IXScreenLogic<T>::loadHeader(const std::string& url)
{
    loadComponent(IXRegistry::inst().get<IXWindowPageHeader>(), url);
}

template<class T>
void IXScreenLogic<T>::loadFooter(const std::string& url)
{
    loadComponent(IXRegistry::inst().get<IXWindowPageFooter>(), url);
}

template class IXScreenLogic<IXStartupScreen>;
template class IXScreenLogic<IXLoginScreen>;
