#include "ixwindownavigationhandler.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

IXWindowNavigationHandler::IXWindowNavigationHandler()
{
    EM_ASM({
       console.log('IXWindowNavigationHandler');
       window.history.pushState({page: 3}, '');
       var popStateHandler = function(e) {
           console.log(e.state);
           var newState = {};
           newState.page = e.state.page - 1;
           console.log(newState);
           window.history.pushState(newState, '');
       };

       window.addEventListener('popstate', popStateHandler);
    });
}
