#ifndef IXBACKENDLESREQDEFS_H
#define IXBACKENDLESREQDEFS_H

#include <list>
#include <functional>

#include "QString"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

struct LOGIN_STATUS
{
    using callbackT = std::function<void(const QString&)>;
    static constexpr const uint32_t ID = 0;

    void request()
    {
        EM_ASM({
                   var resultCallback = function(loginValid) {
                       var result = {};
                       result.loginStatus = loginValid;

                       var data = JSON.stringify(result);
                       var heapPtr = Module._malloc((data.length+1)*2);
                       Module.stringToUTF16(data, heapPtr, (data.length+1)*2);
                       Module._IXBackendLessCallback($0, heapPtr);
                   };

                   Backendless.UserService.isValidLogin().then((res)=>{
                       if(!res) {
                           throw 'Invalid login';
                       }
                       resultCallback(true);
                   }).catch((e)=>{
                       console.log(e);
                       resultCallback(false);
                   });
        }, ID);
    }

    std::list<callbackT> callbacks={};
};

#endif // IXBACKENDLESREQDEFS_H
