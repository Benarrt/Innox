#include "ixgridview.h"

IXGridView::IXGridView(QQuickItem *parent) : QQuickItem(parent), _optimalWidth(0)
{

}

void IXGridView::setup()
{
    connect(_component, SIGNAL(widthChanged()), this, SLOT(calculateOptimalWidth()));
    calculateOptimalWidth();
}

void IXGridView::calculateOptimalWidth()
{
    QObject* model = _gridView->property(META_PROPERTIES::model).value<QObject*>();
    size_t cellWidth = _gridView->property(META_PROPERTIES::cellWidth).toInt();
    size_t gvWidth = _gridView->property(META_PROPERTIES::width).toInt();

    size_t modelCount = model->property(META_PROPERTIES::count).toInt();

    size_t itemSpacingW = _component->property(META_PROPERTIES::itemSpacingW).toInt();
    size_t maxColumns = _component->property(META_PROPERTIES::maxColumns).toInt();
    size_t width = _component->property(META_PROPERTIES::width).toInt();

    size_t maxRowElements = width / cellWidth;

    if(maxRowElements > modelCount)
    {
        maxRowElements = modelCount;
    }

    if(maxRowElements > maxColumns)
    {
        maxRowElements = maxColumns;
    }

    _optimalWidth = (maxRowElements * cellWidth) + (itemSpacingW * 2);

    if(gvWidth != _optimalWidth)
    {
        _gridView->setProperty(META_PROPERTIES::width, _optimalWidth);
    }
}
