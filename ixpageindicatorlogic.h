#ifndef IXPAGEINDICATORLOGIC_H
#define IXPAGEINDICATORLOGIC_H

#include "QQuickItem"

class IXPageIndicatorObserver;
class IXPageIndicatorLogic
{
public:
    IXPageIndicatorLogic(IXPageIndicatorObserver* observer = nullptr);
    ~IXPageIndicatorLogic();
    void updatePageIndex(int index);
    void updatePageCount(int count);

    int pageIndex();
    int pageCount();
};

#endif // IXPAGEINDICATORLOGIC_H
