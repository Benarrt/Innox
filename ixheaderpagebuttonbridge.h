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

    static constexpr delegateData DELEGATES[] =
    {
        {0},
        {1},
        {2},
        {3},
        {4},
        {5},
        {6},
        {7},
        {8},
        {9},
        {10},
        {11},
        {12},
        {13},
        {14}
    };
    static constexpr int DELEGATE_COUNT = 15;
    static constexpr char DELEGATE_URL[] ="qrc:/QIXHeaderPageButton.qml";
};

#endif // IXHEADERPAGEBUTTONBRIDGE_H
