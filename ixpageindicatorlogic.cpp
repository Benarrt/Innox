#include "ixpageindicatorlogic.h"
#include "ixregistry.h"
#include "ixpageindicator.h"
#include "ixwindowpagefooter.h"
#include "ixwindowpage.h"
#include "ixswipeview.h"

IXPageIndicatorLogic::IXPageIndicatorLogic()
{
    qDebug("IXPageIndicatorLogic");
    auto footer = IXRegistry::inst().get<IXWindowPageFooter>();
    auto pageIndicator = footer->component()->findChild<QQuickItem*>("QIXPageIndicator");
    if(pageIndicator)
        qDebug("GOT pageIndicator");

    /*auto page = IXRegistry::inst().get<IXWindowPage>();

    auto pageIndicator = footer->findChild<IXPageIndicator*>("IXPageIndicator");
    auto swipeView = page->findChild<IXSwipeView*>("IXSwipeView");

    QObject::connect(swipeView, &IXSwipeView::indexChanged, pageIndicator, &IXPageIndicator::setIndex);
    pageIndicator->setCount(swipeView->count());*/
}
