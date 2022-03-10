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
                   Backendless.UserService.isValidLogin().then((res)=>{
                       if(!res) {
                           throw 'Invalid login';
                       }
                       window.backendlessCallback($0, true, null, null);
                   }).catch((err)=>{
                       window.backendlessCallback($0, false, null, err.code);
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
                   var email = Module.UTF16ToString($1);
                   var password = Module.UTF16ToString($2);
                   Backendless.UserService.login(email, password, true)
                   .then((session) => {
                       window.backendlessCallback($0, true, null, null);
                   })
                   .catch((err) => {
                       window.backendlessCallback($0, false, null, err.code);
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
                   Backendless.UserService.logout()
                   .then(() => {
                       window.backendlessCallback($0, false, null, null);
                   }).catch((e) => {
                       Backendless.UserService.isValidLogin().then((res)=>{
                           if(!res) {
                               throw 'Invalid login';
                           }
                           window.backendlessCallback($0, true, null, nulll);
                       }).catch((err)=>{
                           window.backendlessCallback($0, false, null, err.code);
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
                   var user = new Backendless.User();
                   user.email = Module.UTF16ToString($1);
                   user.password = Module.UTF16ToString($2);
                   Backendless.UserService.register( user ).then(function(){
                       window.backendlessCallback($0, true, null, null);
                   }, function(err){
                       window.backendlessCallback($0, false, null, err.code);
                   });
        }, ID, username.data(), password.data());
    }

    std::list<callbackT> callbacks={};
};
#define REGISTER_REQ IXBACKENDLESS_REQUEST<REGISTER_REQUEST>

struct PASSWORD_RECOVER_REQUEST
{
    using callbackT = std::function<void(const QString&)>;
    static constexpr const uint32_t ID = 4;

    void request(const QString& username)
    {
        EM_ASM({
                   var email = Module.UTF16ToString($1);
                   Backendless.UserService.restorePassword( email ).then(function(){
                       window.backendlessCallback($0, true, null, null);
                   }, function(err){
                       window.backendlessCallback($0, false, null, err.code);
                   });
        }, ID, username.data());
    }

    std::list<callbackT> callbacks={};
};
#define PW_RECOVER_REQ IXBACKENDLESS_REQUEST<PASSWORD_RECOVER_REQUEST>

#endif // IXBACKENDLESREQDEFS_H
