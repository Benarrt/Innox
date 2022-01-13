#include "ixwindowtabhandler.h"

#include <QQuickWindow>

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

extern "C" {
        void EMSCRIPTEN_KEEPALIVE handleTab()
        {
            IXWindowTabHandler::inst().tabEvent();
        }
}

IXWindowTabHandler::IXWindowTabHandler()
{
    EM_ASM({
       function onTabKeyDown(e) {
         if (e.keyCode == 9) {
           Module._handleTab();
           e.preventDefault();
         }
       };

        document.addEventListener('keydown', onTabKeyDown);
    });

}

void IXWindowTabHandler::tabEvent()
{
    qDebug("tabEvent");
    QKeyEvent * tabEvent = new QKeyEvent (QEvent::KeyPress,Qt::Key_Tab,Qt::NoModifier);
    QCoreApplication::sendEvent(window(), tabEvent);
}
