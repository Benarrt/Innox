#ifndef IXPAGELOGIC_H
#define IXPAGELOGIC_H

#include <string>
#include "ixscreen.h"

class IXDynamicComponent;

class IXScreenLogic
{
public:
    IXScreenLogic(IXScreen* component);

    void loadLoginScreen();
    void loadDealerScreen();
    void loadStartupScreen();

protected:
    void loadComponent(IXDynamicComponent* comp, const std::string& url);
    void loadScreen(const std::string& url);
    void loadHeader(const std::string& url);
    void loadFooter(const std::string& url);

    virtual void load();

    IXScreen* _component;
};

#endif // IXPAGELOGIC_H
