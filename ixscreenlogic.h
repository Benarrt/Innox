#ifndef IXPAGELOGIC_H
#define IXPAGELOGIC_H

#include <string>

class IXDynamicComponent;

template<class T>
class IXScreenLogic
{
public:
    IXScreenLogic();

    void load();

    void loadScreen(const std::string& url);
    void loadHeader(const std::string& url);
    void loadFooter(const std::string& url);

protected:
    void loadComponent(IXDynamicComponent* comp, const std::string& url);
};

#endif // IXPAGELOGIC_H
