#include "ixhandlebackpopup.h"
#include "ixwindownavigationhandler.h"
#include "ixregistry.h"

IXHandleBackPopup::IXHandleBackPopup(QQuickItem* parent) : QQuickItem(parent)
{
    IXRegistry::inst().addToRegistry(this);
}

void IXHandleBackPopup::goBack()
{
    IXWindowNavigationHandler::inst().goBack();
}

