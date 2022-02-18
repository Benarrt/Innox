#ifndef IXSCREEN_H
#define IXSCREEN_H

#include "string"

class IXScreen
{
public:
    IXScreen() {};

    virtual const std::string headerURL() = 0;
    virtual const std::string footerURL() = 0;
};

#endif // IXSCREEN_H
