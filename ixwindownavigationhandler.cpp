#include "ixwindownavigationhandler.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

extern "C" {
        void EMSCRIPTEN_KEEPALIVE handleBack()
        {
            emit IXWindowNavigationHandler::inst().handleBack();
        }
}

IXWindowNavigationHandler::IXWindowNavigationHandler()
{
    EM_ASM({

       var navigationState = {};
       navigationState.allowBack = false;

       window.quitInnox = (function () {
           this.allowBack = true;
       }).bind(navigationState);


      var popStateHandler = function(e) {
           if(!this.allowBack) {
                window.history.pushState({}, '');
                Module._handleBack();
           }
       };

       window.addEventListener('popstate', popStateHandler.bind(navigationState), true);
       window.history.pushState({}, '');
    });
}

void IXWindowNavigationHandler::goBack()
{
    EM_ASM({
       window.quitInnox();
       history.back(0);
       history.back(-1);
    });
}
