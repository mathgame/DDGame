#include "QmlCppCoordinator.h"

#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickView>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickWindow>
#include <QDebug>
#include <QVariantList>

#include "PageStartScreen.h"
#include "PageNewHero.h"
#include "Dependencies.h"
#include "QmlConfig.h"
#include "ViewModel/MainMenuDataModel.h"
#include "ViewModel/MainMenuItem.h"

QQuickWindow* windowPtr = nullptr;
QQmlApplicationEngine* enginePtr = nullptr;
std::map<std::string, qmlCppObject> mapQmlCpp;

qmlCppObject::qmlCppObject()
    : CppPtr(nullptr)
    , QmlPtr(nullptr){}

qmlCppObject::qmlCppObject(QObject* cppPtr, QQuickItem* qmlPtr)
    : CppPtr(cppPtr)
    , QmlPtr(qmlPtr){}

void InitQmlCpp()
{
    enginePtr = new QQmlApplicationEngine();
    enginePtr->load(QUrl(QStringLiteral("qrc:/main.qml")));

    qmlRegisterType<CMainMenuDataModel>("models", 1, 0, "CMainMenuDataModel");

    windowPtr = qobject_cast<QQuickWindow*>(enginePtr->rootObjects().at(0));

    QQuickItem *root = windowPtr->contentItem();

    QQmlComponent component(enginePtr, QUrl("qrc:/Page_StartScreen.qml"));
    QQuickItem *pageStartScreenQml = qobject_cast<QQuickItem*>(component.create());
    QQmlEngine::setObjectOwnership(pageStartScreenQml, QQmlEngine::CppOwnership);
    pageStartScreenQml->setParentItem(root);
    pageStartScreenQml->setParent(enginePtr);

    QQmlComponent component2(enginePtr, QUrl("qrc:/Page_NewHero.qml"));
    QQuickItem *pageNewHeroQml = qobject_cast<QQuickItem*>(component2.create());
    QQmlEngine::setObjectOwnership(pageNewHeroQml, QQmlEngine::CppOwnership);
    pageNewHeroQml->setParentItem(root);
    pageNewHeroQml->setParent(enginePtr);

    PageStartScreen *pageStartScreenCpp = new PageStartScreen();
    PageNewHero *pageNewHeroCpp = new PageNewHero();

    mapQmlCpp["Page_StartScreen"] = qmlCppObject(pageStartScreenCpp, pageStartScreenQml);
    mapQmlCpp["Page_NewHero"] = qmlCppObject(pageNewHeroCpp, pageNewHeroQml);
}

void LoadQmlConfigurations()
{
    auto qmlPageNewHeroPtr = mapQmlCpp.at("Page_NewHero").QmlPtr;
    CMainMenuDataModel* raceModelData =
             qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("raceModelData"));

    for( const auto& race :  QmlConfig::races)
    {
        CMainMenuItem* menuItem = new CMainMenuItem();
        menuItem->SetMenuText(race.toString());
        menuItem->SetEnabled(true);
        menuItem->SetColor("light green");
        raceModelData->append(menuItem);
    }

    CMainMenuDataModel* classModelData =
             qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("classModelData"));

    for( const auto& singleClass :  QmlConfig::classes)
    {
        CMainMenuItem* menuItem = new CMainMenuItem();
        menuItem->SetMenuText(singleClass.toString());
        menuItem->SetEnabled(true);
        menuItem->SetColor("red");
        classModelData->append(menuItem);
    }

    CMainMenuDataModel* abilitiesModelData =
             qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("abilitiesModelData"));

    for( const auto& ability :  QmlConfig::abilities)
    {
        CMainMenuItem* menuItem = new CMainMenuItem();
        menuItem->SetMenuText(ability.toString());
        menuItem->SetEnabled(false);
        menuItem->SetColor("green");
        abilitiesModelData->append(menuItem);
    }


//    auto fillVariantMap = [](const std::string& keyName,
//        const QVariantList& stringList)
//    {
//        QVariantList variantMap;
//        for(const auto& str : stringList)
//        {
//            QVariantMap itemMap;
//            itemMap[keyName.c_str()] = str;
//            variantMap.push_back(itemMap);
//        }
//        return variantMap;
//    };
//    QVariantList racesMap = fillVariantMap("race", QmlConfig::races);
//    QVariantList classesMap = fillVariantMap("class", QmlConfig::classes);
//    QVariantList abilitiesMap = fillVariantMap("abilities", QmlConfig::abilities);
//    dynamic_cast<PageNewHero*>(cppPtr)->setRaces( racesMap );
//    dynamic_cast<PageNewHero*>(cppPtr)->setClasses( classesMap );
//    dynamic_cast<PageNewHero*>(cppPtr)->setAbilities( abilitiesMap );
}

void SetVisiblePage(const std::string& pageName)
{
    //TODO call all viewmodel objects clear functions before changing the page
    for(auto& iter : mapQmlCpp)
    {
        iter.second.CppPtr->setProperty("visible", false);
        qobject_cast<QQuickItem*>(iter.second.QmlPtr)->setParentItem(nullptr);
    }

    QQuickItem *root = windowPtr->contentItem();
    auto iter = mapQmlCpp.find(pageName);
    if( iter == mapQmlCpp.end() )
    {
        qDebug() << "Page name doesn't exist in map : ";
    }
    auto cppQmlObj = iter->second;

    cppQmlObj.CppPtr->setProperty("visble", true);
    qobject_cast<QQuickItem*>(cppQmlObj.QmlPtr)->setParentItem(root);
}

QQuickWindow *GetWindowPtr()
{
    return windowPtr;
}

QQmlApplicationEngine *GetEnginePtr()
{
    return enginePtr;
}

std::map<std::string, qmlCppObject> &GetMapQmlCpp()
{
    return mapQmlCpp;
}

void ConnectSignals()
{
    auto startScreenCppPtr = GetMapQmlCpp().at("Page_StartScreen").CppPtr;
    auto startScreenQmlPtr = GetMapQmlCpp().at("Page_StartScreen").QmlPtr;

    QObject::connect(startScreenQmlPtr, SIGNAL(signalNewGame()),
                     startScreenCppPtr, SLOT(slotNewGame()));

    QObject::connect(startScreenQmlPtr, SIGNAL(signalLoadGame()),
                     startScreenCppPtr, SLOT(slotLoadGame()));


    auto newHeroCppPtr = GetMapQmlCpp().at("Page_NewHero").CppPtr;
    auto newHeroQmlPtr = GetMapQmlCpp().at("Page_NewHero").QmlPtr;

    QObject::connect(newHeroQmlPtr, SIGNAL(signalOnRaceSelect(QString)),
                     newHeroCppPtr, SLOT(slotOnRaceSelected(QString)));

    QObject::connect(newHeroQmlPtr, SIGNAL(signalOnClassSelect(QString)),
                     newHeroCppPtr, SLOT(slotOnClassSelected(QString)));

    QObject::connect(newHeroCppPtr, SIGNAL(signalSetRaces(QVariant)),
                     newHeroQmlPtr, SIGNAL(signalSetRaces(QVariant)));

    QObject::connect(newHeroCppPtr, SIGNAL(signalSetClasses(QVariant)),
                     newHeroQmlPtr, SIGNAL(signalSetClasses(QVariant)));

    QObject::connect(newHeroCppPtr, SIGNAL(signalSetAbilities(QVariant)),
                     newHeroQmlPtr, SIGNAL(signalSetAbilities(QVariant)));
}

