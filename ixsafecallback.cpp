#include "ixsafecallback.h"
std::unordered_set<IXSafeCallback*> IXSafeCallback::s_registry;

IXSafeCallback::IXSafeCallback()
{
    s_registry.insert(this);
}

IXSafeCallback::~IXSafeCallback()
{
    auto it = s_registry.find(this);
    if(it != s_registry.end())
        s_registry.erase(it);
}


