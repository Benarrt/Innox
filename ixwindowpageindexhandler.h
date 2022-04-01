#ifndef IXWINDOWPAGEINDEXHANDLER_H
#define IXWINDOWPAGEINDEXHANDLER_H

#include "unordered_map"
#include <QQuickItem>

class IXPageIndicatorLogic;

class IXWindowPageIndexHandler : public QQuickItem
{
    using callbackT = std::function<void(int)>;
    Q_OBJECT
    Q_PROPERTY(int pageIndex MEMBER _pageIndex NOTIFY pageIndexChanged)
    Q_PROPERTY(int pageCount MEMBER _pageCount NOTIFY pageCountChanged)
public:
    static IXWindowPageIndexHandler& inst()
    {
        static IXWindowPageIndexHandler instance;
        return instance;
    }

    static const IXWindowPageIndexHandler& cinst()
    {
        return IXWindowPageIndexHandler::inst();
    }

    void addIndexObserver(IXPageIndicatorLogic*, callbackT);
    void addCountObserver(IXPageIndicatorLogic*, callbackT);

    void removeIndexObserver(IXPageIndicatorLogic*);
    void removeCountObserver(IXPageIndicatorLogic*);

    void updatePageIndex(int);
    void updatePageCount(int);

    int getPageIndex();
    int getPageCount();

signals:
    void pageIndexChanged(int);
    void pageCountChanged(int);

private:
    IXWindowPageIndexHandler();

    void notifyIndexObservers();
    void notifyCountObservers();

    std::unordered_map<IXPageIndicatorLogic*, callbackT> _indexObservers;
    std::unordered_map<IXPageIndicatorLogic*, callbackT> _countObservers;

    int _pageIndex;
    int _pageCount;
};

#endif // IXWINDOWPAGEINDEXHANDLER_H
