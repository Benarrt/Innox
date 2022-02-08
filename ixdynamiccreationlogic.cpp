#include "ixdynamiccreationlogic.h"
#include "ixstartupscreen.h"
#include "ixloginscreen.h"

template<class T>
IXDynamicCreationLogic<T>::IXDynamicCreationLogic(T* object)
{
    QMetaObject::Connection* connection = new QMetaObject::Connection;
    *connection = QObject::connect(object, &QQuickItem::enabledChanged, object,
    [this, connection, object]()
    {
        if(object->isEnabled())
        {
            QObject::disconnect(*connection);
            delete connection;
            dynamicReady();
        }
    });
}

template class IXDynamicCreationLogic<IXStartupScreen>;
template class IXDynamicCreationLogic<IXLoginScreen>;
