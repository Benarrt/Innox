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

    Q_INVOKABLE QColor superLightColor()
    {
        return QColor(0xf5faff);
    }

    Q_INVOKABLE QColor lightColor()
    {
        return QColor(0xCCD4DD);
    }

    Q_INVOKABLE QColor mediumColor()
    {
        return QColor(0x446063);
    }

    Q_INVOKABLE QColor darkColor()
    {
        return QColor(0x141e1d);
    }

    Q_INVOKABLE QFont defaultFont()
    {
        static QFont font("Verdana", 16);
        return font;
    }

private:
    explicit IXStyleSheet(QObject *parent = nullptr);

signals:

};

#endif // IXSTYLESHEET_H
