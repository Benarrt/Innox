#include "ixhandlebackpopup.h"
#include "ixwindownavigationhandler.h"

IXHandleBackPopup::IXHandleBackPopup(QQuickItem* parent) : QQuickItem(parent)
{

}

void IXHandleBackPopup::goBack()
{
    IXWindowNavigationHandler::inst().goBack();
}

