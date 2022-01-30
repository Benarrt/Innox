#ifndef IXPAGELOGIC_H
#define IXPAGELOGIC_H

#include <string>

class IXScreenLogic
{
public:
    IXScreenLogic();

    void loadScreen(const std::string& url);
    void loadHeader(const std::string& url);
    void loadFooter(const std::string& url);

    void hideHeader();
    void hideFooter();
};

#endif // IXPAGELOGIC_H
