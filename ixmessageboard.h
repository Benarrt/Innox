#ifndef IXMESSAGEBOARD_H
#define IXMESSAGEBOARD_H

#include <list>

#include <QQuickItem>
#include "ixqcomponent.h"
#include "QList"


class IXMessageBoard : public QQuickItem
{
    Q_OBJECT
    IX_Q_COMPONENT

    Q_INVOKABLE void clear();
    Q_INVOKABLE void addMessage(int msgID);
    Q_INVOKABLE void addMessages(const QList<int>& msgIDs);
public:
    IXMessageBoard();

protected:
    struct META_PROPERTIES
    {
        static constexpr char model[] = "model";
        static constexpr char desiredHeight[] = "desiredHeight";
    };

    struct META_METHODS
    {
        static constexpr char clear[] = "clear";
        static constexpr char pushBack[] = "pushBack";
    };


    void componentComplete() override;

    std::list<int> msgList;
};

#endif // IXMESSAGEBOARD_H
