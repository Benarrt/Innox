#ifndef IXSTYLESHEET_H
#define IXSTYLESHEET_H

#include <QObject>
#include "QColor"
#include "QFont"

class QQmlEngine;
class QJSEngine;

class IXStyleSheet : public QObject
{
    Q_OBJECT
public:
    static IXStyleSheet* instance()
    {
        static  IXStyleSheet inst;
        return &inst;
    }

    static QObject* qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
    {
        Q_UNUSED(engine);
        Q_UNUSED(scriptEngine);
        return IXStyleSheet::instance();
    }

    Q_INVOKABLE QColor bgColor()
    {
        return QColor(0x8fb9a8);
    }

    Q_INVOKABLE QColor bg2Color()
    {
        return QColor("black");
    }

    Q_INVOKABLE QColor fgColor()
    {
        return QColor(0xfefad4);
    }

    Q_INVOKABLE QColor fg2Color()
    {
        return QColor(0xFFFFFF);
    }

    Q_INVOKABLE QColor fg3Color()
    {
        return QColor(0xFCD0BA);
    }

    Q_INVOKABLE QFont fgFont()
    {
        static QFont font("Verdana", 16);
        return font;
    }

private:
    explicit IXStyleSheet(QObject *parent = nullptr);

signals:

};

#endif // IXSTYLESHEET_H
