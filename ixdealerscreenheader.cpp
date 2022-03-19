#include "ixdealerscreenheader.h"

IXDealerScreenHeader::IXDealerScreenHeader() : _logic(this)
{

}

void IXDealerScreenHeader::logOut()
{
    _logic.logOut();
}

void IXDealerScreenHeader::onDynamicReady()
{

}

void IXDealerScreenHeader::validLoginCallback()
{

}

void IXDealerScreenHeader::invalidLoginCallback(uint16_t error)
{
    _logic.loadStartupScreen();
}
