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

struct LOGIN_REQUEST
{
    using callbackT = std::function<void(const QString&)>;
    static constexpr const uint32_t ID = 1;

    void request(const QString& username, const QString& password)
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

                   var email = Module.UTF16ToString($1);
                   var password = Module.UTF16ToString($2);
                   Backendless.UserService.login(email, password, true)
                   .then((session) => {
                       resultCallback(true);
                   })
                   .catch((e) => {
                       console.log(e);
                       resultCallback(false);
                   });
        }, ID, username.data(), password.data());
    }

    std::list<callbackT> callbacks={};
};

struct LOGOUT_REQUEST
{
    using callbackT = std::function<void(const QString&)>;
    static constexpr const uint32_t ID = 2;

    void request()
    {
        qDebug("LOGOUT_REQUEST");

        EM_ASM({
                   var resultCallback = function(loginValid) {
                       var result = {};
                       result.loginStatus = loginValid;

                       var data = JSON.stringify(result);
                       var heapPtr = Module._malloc((data.length+1)*2);
                       Module.stringToUTF16(data, heapPtr, (data.length+1)*2);
                       Module._IXBackendLessCallback($0, heapPtr);
                   };

                   Backendless.UserService.logout()
                   .then(() => {
                       resultCallback(false);
                   }).catch((e) => {
                       Backendless.UserService.isValidLogin().then((res)=>{
                           if(!res) {
                               throw 'Invalid login';
                           }
                           resultCallback(true);
                       }).catch((e)=>{
                           console.log(e);
                           resultCallback(false);
                       });
                   });
        }, ID);
    }

    std::list<callbackT> callbacks={};
};

struct REGISTER_REQUEST
{
    using callbackT = std::function<void(const QString&)>;
    static constexpr const uint32_t ID = 3;

    void request(const QString& username, const QString& password)
    {
        EM_ASM({
                   var resultCallback = function(error) {
                       console.log(error);
                   };

                   var user = new Backendless.User();
                   user.email = Module.UTF16ToString($1);
                   user.password = Module.UTF16ToString($2);
                   Backendless.UserService.register( user ).then(function(){
                       console.log("REGISTER OK");
                       console.log(msg);
                   }, function(err){
                       console.log("REGISTER FAIL");
                       console.log(err);
                   }).catch(err=>{
                       console.log("REGISTER FAIL2");
                       console.log(err);
                   })
        }, ID, username.data(), password.data());
    }

    std::list<callbackT> callbacks={};
};
#define REGISTER_REQ IXBACKENDLESS_REQUEST<REGISTER_REQUEST>

#endif // IXBACKENDLESREQDEFS_H
