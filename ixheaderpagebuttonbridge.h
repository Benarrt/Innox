#ifndef IXHEADERPAGEBUTTONBRIDGE_H
#define IXHEADERPAGEBUTTONBRIDGE_H

#include <QQuickItem>
#include "ixpageindicatorlogic.h"
#include "ixpageindicatorobserver.h"

class IXHeaderPageButtonBridge : public QQuickItem, public IXPageIndicatorObserver
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex MEMBER _currentIndex NOTIFY currentIndexChanged)
public:
    IXHeaderPageButtonBridge();

    Q_INVOKABLE int delegatesCount();
    Q_INVOKABLE QString delegateUrl();

    Q_INVOKABLE void feedPageNameListModel(QObject*);
    Q_INVOKABLE QString pageName(int);

    Q_INVOKABLE void feedModel(QObject*);

    Q_SIGNAL void currentIndexChanged();

    Q_SLOT void onPageIndexChanged(int) override;
    Q_SLOT void onPageCountChanged(int) override;
    Q_SLOT void onCurrenIndexChanged();

private:
    struct Logic : public IXPageIndicatorLogic
    {
        using IXPageIndicatorLogic::IXPageIndicatorLogic;
    };

    Logic _logic;
    QObject* _pageNameListModel;
    int _currentIndex;

    struct delegateData
    {
        int itemId;
    };

    struct META_METHODS
    {
        static constexpr char clear[] = "clear";
        static constexpr char pushBack[] = "pushBack";
    };

    static constexpr delegateData DELEGATES[] =
    {
        {0},
        {1}
    };
    static constexpr int DELEGATE_COUNT = 2;
    static constexpr char DELEGATE_URL[] ="qrc:/QIXHeaderPageButton.qml";
};

#endif // IXHEADERPAGEBUTTONBRIDGE_H
