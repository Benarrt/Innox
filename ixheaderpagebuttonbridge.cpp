#include "ixheaderpagebuttonbridge.h"

IXHeaderPageButtonBridge::IXHeaderPageButtonBridge() : _logic(this), _pageNameListModel(nullptr), _currentIndex(0)
{
    connect(this, &IXHeaderPageButtonBridge::currentIndexChanged, this, &IXHeaderPageButtonBridge::onCurrenIndexChanged);

    onPageCountChanged(_logic.pageCount());
    onPageIndexChanged(_logic.pageIndex());
}

void IXHeaderPageButtonBridge::onPageIndexChanged(int index)
{
    _currentIndex = index;
    emit currentIndexChanged();
}

void IXHeaderPageButtonBridge::onPageCountChanged(int)
{

}

void IXHeaderPageButtonBridge::onCurrenIndexChanged()
{
    if(_currentIndex < _logic.pageCount())
        _logic.updatePageIndex(_currentIndex);
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

