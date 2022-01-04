#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ixwindow.h>
#include <ixpage.h>
#include <ixtextfield.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<IXWindow>("io.qt.examples.ixwindow", 1, 0, "IXWindow");
    qmlRegisterType<IXPage>("io.qt.examples.ixpage", 1, 0, "IXPage");
    qmlRegisterType<IXTextField>("io.qt.examples.ixtextfield", 1, 0, "IXTextField");

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
