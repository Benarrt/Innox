#ifndef IXPAGELOGIC_H
#define IXPAGELOGIC_H

#include <string>

class IXScreenLogic
{
public:
    IXScreenLogic();

    void loadScreen(const std::string& url);
    void loadHeader(const std::string& url);
};

#endif // IXPAGELOGIC_H
