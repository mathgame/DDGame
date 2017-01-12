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
    auto fillVariantMap = [](const std::string& keyName,
        const QVariantList& stringList)
    {
        QVariantList variantMap;
        for(const auto& str : stringList)
        {
            QVariantMap itemMap;
            itemMap[keyName.c_str()] = str;
            variantMap.push_back(itemMap);
        }
        return variantMap;
    };

    //TODO READ FROM CONFIG FILE
    QVariantList races = {"Human", "Orc", "Elf", "Dwarf", "Dark Elf"};
    QVariantList classes = {"Paladin", "Warrior", "Archer", "Magician", "Druid", "Rogue", "Priest", "Warlock", "Elder"};
    QVariantList abilities = {"Power Shot", "Power Arrow", "Power Ice", "Power Fire", "LOL", "IMBA", "DONT PICK ME", "Newbie", "Trash"
                        "Ultimate", "Electricity", "Fire", "Ice", "Dawn", "Dog", "Cat", "Dummy", "Word", "Hunger",
                        "Col", "Reel", "Heart", "Sun", "Kiss", "Love"};

    QVariantList racesMap = fillVariantMap("race", races);
    QVariantList classesMap = fillVariantMap("class", classes);
    QVariantList abilitiesMap = fillVariantMap("abilities", abilities);

    auto cppPtr = mapQmlCpp.at("Page_NewHero").CppPtr;
    dynamic_cast<PageNewHero*>(cppPtr)->setRaces( racesMap );
    dynamic_cast<PageNewHero*>(cppPtr)->setClasses( classesMap );
    dynamic_cast<PageNewHero*>(cppPtr)->setAbilities( abilitiesMap );
}

void SetVisiblePage(const std::string& pageName)
{
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

