#include "ixlistview.h"

IXListView::IXListView(QQuickItem *parent) : QQuickItem(parent), _optimalWidth(0)
{

}

void IXListView::setup()
{
    connect(_component, SIGNAL(widthChanged()), this, SLOT(calculateOptimalWidth()));
    calculateOptimalWidth();
}


void IXListView::calculateOptimalWidth()
{
    QObject* model = _listView->property(META_PROPERTIES::model).value<QObject*>();
    size_t lvWidth = _listView->property(META_PROPERTIES::width).toInt();

    size_t modelCount = model->property(META_PROPERTIES::count).toInt();

    size_t itemW = _component->property(META_PROPERTIES::itemW).toInt();
    size_t itemSpacingW = _component->property(META_PROPERTIES::itemSpacingW).toInt();
    size_t width = _component->property(META_PROPERTIES::width).toInt();

    size_t contentWidth = itemW + itemSpacingW;

    //qDebug(QString("contentWidth: %1 modelCount: %2 itemSpacingW: %3").arg(
      //         QString::number(contentWidth), QString::number(modelCount), QString::number(itemSpacingW)).toLocal8Bit());

    _optimalWidth = modelCount * contentWidth + (itemSpacingW*2);
    //qDebug(QString("Width : %1/%2").arg(QString::number(_optimalWidth), QString::number(width)).toLocal8Bit());
    if(_optimalWidth > width)
    {
        _optimalWidth = width;
        _listView->setProperty(META_PROPERTIES::interactive, true);
    }
    else
    {
        _listView->setProperty(META_PROPERTIES::interactive, false);
    }

    if(lvWidth != _optimalWidth)
    {
        _listView->setProperty(META_PROPERTIES::width, _optimalWidth);
    }
}
