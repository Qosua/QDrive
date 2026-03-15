#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "window-format.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
                     &WindowFormat::setupWindowFormat);

    engine.load("qrc:/views/windows-linux/main.qml");

    return app.exec();
}
