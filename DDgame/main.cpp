#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "QtMacros.h"
#include "QmlCppCoordinator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    InitQmlCpp();
    GetWindowPtr()->show();

    auto startScreenCppPtr = GetMapQmlCpp().at("Page_StartScreen").CppPtr;
    auto startScreenQmlPtr = GetMapQmlCpp().at("Page_StartScreen").QmlPtr;

    QObject::connect(startScreenQmlPtr, SIGNAL(signalNewGame()),
                     startScreenCppPtr, SLOT(slotNewGame()));

    QObject::connect(startScreenQmlPtr, SIGNAL(signalLoadGame()),
                     startScreenCppPtr, SLOT(slotLoadGame()));


    auto newHeroCppPtr = GetMapQmlCpp().at("Page_NewHero").CppPtr;
    auto newHeroQmlPtr = GetMapQmlCpp().at("Page_NewHero").QmlPtr;

    QObject::connect(newHeroCppPtr, SIGNAL(signalSetRaces(QVariant)),
                     newHeroQmlPtr, SIGNAL(signalSetRaces(QVariant)));

    QObject::connect(newHeroCppPtr, SIGNAL(signalSetClasses(QVariant)),
                     newHeroQmlPtr, SIGNAL(signalSetClasses(QVariant)));

    QObject::connect(newHeroCppPtr, SIGNAL(signalSetAbilities(QVariant)),
                     newHeroQmlPtr, SIGNAL(signalSetAbilities(QVariant)));

    LoadQmlConfigurations();

    SetVisiblePage("Page_StartScreen");

//    qmlCppCoordinator<PageStartScreen> pageStartScreenCRD;
//    pageStartScreenCRD.GetCpp();
//    pageStartScreenCRD.GetQml();


//    QObject::connect(pageStartScreen, SIGNAL(newGameSignal(QString)),
//            pageStartScreenObject, SIGNAL(newGameSignal(QString)));


//    QObject *dataChannel3 = NULL;
//    CREATE_QML_OBJECT(dataChannel3, QUrl("qrc:/Page_StartScreen.qml"), engine, mainQML);

//    DataChannel dataChannel;
//    QObject::connect(&dataChannel, SIGNAL(loaderSignal(QString)),
//            pageLoader, SIGNAL(loaderSignal(QString)));

// dataChannel.testFunc(); C++ To QML

    return app.exec();
}
