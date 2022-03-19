#include "ixscreenlogic.h"
#include "ixregistry.h"
#include "ixwindowpage.h"
#include "ixwindowpageheader.h"
#include "ixwindowpagefooter.h"
#include "ixstartupscreen.h"
#include "ixloginscreen.h"

IXScreenLogic::IXScreenLogic(IXScreen* component) : _component(component)
{
    load();
}

void IXScreenLogic::loadComponent(IXDynamicComponent* comp, const std::string& url)
{
    if(comp)
        comp->setUrl(QString::fromStdString(url));
}

void IXScreenLogic::load()
{
    if(_component == nullptr)
        return;

    loadHeader(_component->headerURL());
    loadFooter(_component->footerURL());
}

void IXScreenLogic::loadScreen(const std::string& url)
{
    loadComponent(IXRegistry::inst().get<IXWindowPage>(), url);
}

void IXScreenLogic::loadHeader(const std::string& url)
{
    loadComponent(IXRegistry::inst().get<IXWindowPageHeader>(), url);
}

void IXScreenLogic::loadFooter(const std::string& url)
{
    loadComponent(IXRegistry::inst().get<IXWindowPageFooter>(), url);
}

void IXScreenLogic::loadLoginScreen()
{
    loadScreen("qrc:/QIXLoginScreen.qml");
}

void IXScreenLogic::loadDealerScreen()
{
    loadScreen("qrc:/QIXDealerScreen.qml");
}

void IXScreenLogic::loadStartupScreen()
{
    loadScreen("qrc:/QIXStartupScreen.qml");
}

