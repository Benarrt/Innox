#include "ixpageindicatorlogic.h"
#include "ixregistry.h"
#include "ixpageindicator.h"
#include "ixwindowpagefooter.h"

IXPageIndicatorLogic::IXPageIndicatorLogic()
{
}

void IXPageIndicatorLogic::upadtePageIndicator(int index, int count)
{
    auto footer = IXRegistry::inst().get<IXWindowPageFooter>();
    auto pageIndicator = footer->findChild<IXPageIndicator*>("IXPageIndicator");

    if(!pageIndicator)
    {
        qDebug("Missing pageIndicator");
        return;
    }

    pageIndicator->component()->setProperty("count", count);
    pageIndicator->component()->setProperty("currentIndex", index);
}

