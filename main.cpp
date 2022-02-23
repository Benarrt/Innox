#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ixwindow.h"
#include "ixwindowpage.h"
#include "ixtextfield.h"
#include "ixbutton.h"
#include "ixhandlebackpopup.h"
#include "ixwindowpageheader.h"
#include "ixstartupscreen.h"
#include "ixloginscreen.h"
#include "ixwindowpagefooter.h"
#include "ixswipeview.h"
#include "ixpageindicator.h"
#include "ixstylesheet.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<IXWindow>("io.qt.examples.ixwindow", 1, 0, "IXWindow");
    qmlRegisterType<IXWindowPage>("io.qt.examples.ixwindowpage", 1, 0, "IXWindowPage");
    qmlRegisterType<IXTextField>("io.qt.examples.ixtextfield", 1, 0, "IXTextField");
    qmlRegisterType<IXButton>("io.qt.examples.ixbutton", 1, 0, "IXButton");
    qmlRegisterType<IXHandleBackPopup>("io.qt.examples.ixhandlebackpopup", 1, 0, "IXHandleBackPopup");
    qmlRegisterType<IXWindowPageHeader>("io.qt.examples.ixwindowpageheader", 1, 0, "IXWindowPageHeader");
    qmlRegisterType<IXStartupScreen>("io.qt.examples.ixstartupscreen", 1, 0, "IXStartupScreen");
    qmlRegisterType<IXLoginScreen>("io.qt.examples.ixloginscreen", 1, 0, "IXLoginScreen");
    qmlRegisterType<IXWindowPageFooter>("io.qt.examples.ixwindowpagefooter", 1, 0, "IXWindowPageFooter");
    qmlRegisterType<IXSwipeView>("io.qt.examples.ixswipeview", 1, 0, "IXSwipeView");
    qmlRegisterType<IXPageIndicator>("io.qt.examples.ixpageindicator", 1, 0, "IXPageIndicator");

    qmlRegisterSingletonType<IXStyleSheet>("io.qt.examples.ixstylesheet", 1, 0, "IXStyleSheet", &IXStyleSheet::qmlInstance);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
