#ifndef IXPAGEINDICATOROBSERVER_H
#define IXPAGEINDICATOROBSERVER_H


class IXPageIndicatorObserver
{
public:
    IXPageIndicatorObserver();

    virtual void onPageIndexChanged(int) = 0;
    virtual void onPageCountChanged(int) = 0;
};

#endif // IXPAGEINDICATOROBSERVER_H
