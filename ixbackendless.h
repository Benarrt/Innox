#ifndef IXBACKENDLESS_H
#define IXBACKENDLESS_H

#include <functional>
#include <list>
#include <unordered_map>

#include "QString"

struct LOGIN_STATUS
{
    using callbackT = std::function<void(const QString&)>;

    static constexpr const uint32_t ID = 0;
    static std::list<callbackT>& callbacks()
    {
        static std::list<callbackT> cbs={};
        return cbs;
    }

    static void callBack(const QString& message)
    {
        auto& _callbacks = callbacks();
        while(!_callbacks.empty())
        {
            _callbacks.front()(message);
            _callbacks.pop_front();
        }
    }

    static void call(callbackT callback)
    {
        auto& _callbacks = callbacks();
        _callbacks.push_back(callback);

        if(_callbacks.size() > 1)
            return;

        request();
    }

private:
    LOGIN_STATUS();

    static void request();
};

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

    static const std::unordered_map<uint32_t, callbackT>& callbackMap()
    {
        static const std::unordered_map<uint32_t, callbackT> map =
        {
              { LOGIN_STATUS::ID, &LOGIN_STATUS::callBack }
        };
        return map;
    }

    template <class T>
    void request(callbackT callback)
    {
        T::call(callback);
    }

private:
    IXBackendLess();

    static constexpr char APP_ID[] = "BFD43D22-2D65-3182-FFA7-565F598C3C00";
    static constexpr char APP_KEY[] = "E88DD8FF-C935-4EAE-8947-9955B5EC1306";
};

#endif // IXBACKENDLESS_H
