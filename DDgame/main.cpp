#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "QtMacros.h"
#include "QmlCppCoordinator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    InitQmlCpp();

    ConnectSignals();

    LoadQmlConfigurations();

    SetVisiblePage("Page_StartScreen");

    GetWindowPtr()->show();

    return app.exec();
}
