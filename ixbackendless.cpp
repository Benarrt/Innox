#include "ixbackendless.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

extern "C"
{
    void EMSCRIPTEN_KEEPALIVE IXBackendLessCallback(uint32_t id ,const QChar* data)
    {
        IXBackendLess::inst().callBack(id, QString(data));
    }
}

IXBackendLess::IXBackendLess() :
    _loginStatusCall(false)
{
    EM_ASM({
       Backendless.serverURL = 'https://eu-api.backendless.com';
       Backendless.initApp(Module.UTF16ToString($0), Module.UTF16ToString($1));
    }, QString::fromLocal8Bit(APP_ID).data(), QString::fromLocal8Bit(APP_KEY).data());
}

void IXBackendLess::callBack(uint32_t id, const QString& message)
{
    if(id == 0)
    {
        while(!_loginStatusCallbacks.empty())
        {
            _loginStatusCallbacks.front()(message);
            _loginStatusCallbacks.pop_front();
        }
        _loginStatusCall = false;
    }
}

void IXBackendLess::loginStatus(callbackT cb)
{
    _loginStatusCallbacks.push_back(cb);
    if(_loginStatusCall)
        return;

    _loginStatusCall = true;
    EM_ASM({
               Backendless.UserService.isValidLogin().then((res)=>{
                   if(!res) {
                       throw 'Invalid login';
                   }
                   var dataStr = "OK";
                   var heapPtr = Module._malloc((dataStr.length+1)*2);
                   Module.stringToUTF16(dataStr, heapPtr, (dataStr.length+1)*2);
                   Module._IXBackendLessCallback(0, heapPtr);
               }).catch((e)=>{
                   console.log(e);
                   var dataStr = "BAD";
                   var heapPtr = Module._malloc((dataStr.length+1)*2);
                   Module.stringToUTF16(dataStr, heapPtr, (dataStr.length+1)*2);
                   Module._IXBackendLessCallback(0, heapPtr);
               });
    });
}
