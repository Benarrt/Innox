#ifndef IXSAFECALLBACK_H
#define IXSAFECALLBACK_H

#include <unordered_set>
#include <functional>

class IXSafeCallback
{
public:
    IXSafeCallback();
    virtual ~IXSafeCallback();

    template<class T, class ...argsT>
    std::function<void(argsT...)> safeCallback(void(T::*func)(argsT...))
    {
        return [this, func](argsT... args)
        {
            auto it = IXSafeCallback::s_registry.find(this);

            if(it == s_registry.end())
                return;

            (reinterpret_cast<T*>(this)->*func)(args...);
        };
    }

    template<class ...argsT>
    std::function<void(argsT...)> safeCallbackLambda(std::function<void(argsT...)>func)
    {
        return [this, func](argsT... args)
        {
            auto it = IXSafeCallback::s_registry.find(this);

            if(it == s_registry.end())
                return;

            func(args...);
        };
    }

protected:
    static std::unordered_set<IXSafeCallback*> s_registry;
};

#endif // IXSAFECALLBACK_H
