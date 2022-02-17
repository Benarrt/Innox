#include "ixbackendless.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

extern "C"
{
    void EMSCRIPTEN_KEEPALIVE IXBackendLessCallback(uint32_t id ,const QChar* data)
    {
        auto cbMap = IXBackendLess::inst().callbackMap();
        auto it = cbMap.find(id);
        if(it != cbMap.end())
        {
            it->second(QString(data));
        }
    }
}

void LOGIN_STATUS::request()
{
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

IXBackendLess::IXBackendLess()
{
    EM_ASM({
       Backendless.serverURL = 'https://eu-api.backendless.com';
       Backendless.initApp(Module.UTF16ToString($0), Module.UTF16ToString($1));
    }, QString::fromLocal8Bit(APP_ID).data(), QString::fromLocal8Bit(APP_KEY).data());
}
