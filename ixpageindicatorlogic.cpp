#include "ixpageindicatorlogic.h"
#include "ixregistry.h"
#include "ixpageindicator.h"
#include "ixwindowpagefooter.h"
#include "ixwindowpage.h"
#include "ixswipeview.h"

IXPageIndicatorLogic::IXPageIndicatorLogic()
{

}

void IXPageIndicatorLogic::connectSVWithFooter()
{
    auto footer = IXRegistry::inst().get<IXWindowPageFooter>();
    auto page = IXRegistry::inst().get<IXWindowPage>();

    auto pageIndicator = footer->findChild<IXPageIndicator*>("IXPageIndicator");
    auto swipeView = page->findChild<IXSwipeView*>("IXSwipeView");

    //QObject::connect(swipeView->parentItem(), SIGNAL(currentIndexChanged()), pageIndicator, [pageIndicator, swipeView](){
        //pageIndicator->setIndex();
    //});
}
