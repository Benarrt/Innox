#include "ixheaderpagebuttonbridge.h"

IXHeaderPageButtonBridge::IXHeaderPageButtonBridge() : _pageNameListModel(nullptr), _currentIndex(0)
{
    qDebug("IXHeaderPageButtonBridge");
}

int IXHeaderPageButtonBridge::delegatesCount()
{
    return DELEGATE_COUNT;
}

QString IXHeaderPageButtonBridge::delegateUrl()
{
    return QString::fromLocal8Bit(DELEGATE_URL);
}

void IXHeaderPageButtonBridge::feedPageNameListModel(QObject* pageNameListModel)
{
    _pageNameListModel = pageNameListModel;
}

QString IXHeaderPageButtonBridge::pageName(int index)
{
    assert(_pageNameListModel);

    QVariant res;
    QVariant arg(index);
    QMetaObject::invokeMethod(_pageNameListModel, "pageName", Qt::DirectConnection,
                              Q_RETURN_ARG(QVariant, res),
                              Q_ARG(QVariant, arg));

    return res.toString();
}

