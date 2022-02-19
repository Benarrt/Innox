#include "ixbackendless.h"
#include "ixbackendlesreqdefs.h"

extern "C"
{
    void EMSCRIPTEN_KEEPALIVE IXBackendLessCallback(uint32_t id ,const QChar* data)
    {
        auto& cbMap = IXBackendLess::callbackMap();
        auto it = cbMap.find(id);
        if(it != cbMap.end())
        {
            it->second(QString(data));
        }
    }
}

template <class T>
class IXBACKENDLESS_REQUEST
{
    using callbackT = std::function<void(const QString&)>;
public:
    static IXBACKENDLESS_REQUEST& inst()
    {
        static IXBACKENDLESS_REQUEST instance;
        return instance;
    }

    static const IXBACKENDLESS_REQUEST& cinst()
    {
        return inst;
    }

    void callBack(const QString& message)
    {
        auto& callbacks = request().callbacks;
        while(!callbacks.empty())
        {
            callbacks.front()(message);
            callbacks.pop_front();
        }
    }

    void call(callbackT callback)
    {
        auto& callbacks = request().callbacks;
        callbacks.push_back(callback);

        if(callbacks.size() > 1)
            return;

        request().request();
    }

private:
    IXBACKENDLESS_REQUEST()
    {

    }

    T& request()
    {
        static T req;
        return req;
    }
};

const std::unordered_map<uint32_t, IXBackendLess::callbackT>& IXBackendLess::callbackMap()
{
    static const std::unordered_map<uint32_t, callbackT> map =
    {
          { LOGIN_STATUS::ID, std::bind(&IXBACKENDLESS_REQUEST<LOGIN_STATUS>::callBack,
            IXBACKENDLESS_REQUEST<LOGIN_STATUS>::inst(), std::placeholders::_1 )}
    };
    return map;
}

IXBackendLess::IXBackendLess()
{
    EM_ASM({
       Backendless.serverURL = 'https://eu-api.backendless.com';
       Backendless.initApp(Module.UTF16ToString($0), Module.UTF16ToString($1));
    }, QString::fromLocal8Bit(APP_ID).data(), QString::fromLocal8Bit(APP_KEY).data());
}

void IXBackendLess::loginStatus(callbackT callback)
{
    IXBACKENDLESS_REQUEST<LOGIN_STATUS>::inst().call(callback);
}