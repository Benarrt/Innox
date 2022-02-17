#ifndef IXBACKENDLESS_H
#define IXBACKENDLESS_H

#include <functional>
#include <unordered_map>
#include "QString"

class IXBackendLess
{
    using callbackT = std::function<void(const QString&)>;
public:

    static IXBackendLess& inst()
    {
        static IXBackendLess instance;
        return instance;
    }

    static const IXBackendLess& cinst()
    {
        return inst();
    }

    void loginStatus(callbackT callback);

    static const std::unordered_map<uint32_t, callbackT>& callbackMap();

private:
    IXBackendLess();

    template <class T>
    void request(callbackT callback)
    {
        T::call(callback);
    }

    static constexpr char APP_ID[] = "BFD43D22-2D65-3182-FFA7-565F598C3C00";
    static constexpr char APP_KEY[] = "E88DD8FF-C935-4EAE-8947-9955B5EC1306";
};

#endif // IXBACKENDLESS_H
