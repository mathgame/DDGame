#include "PageNewHero.h"
#include "QmlCppCoordinator.h"
#include "Dependencies.h"
#include "QmlConfig.h"
#include "ViewModel/MainMenuDataModel.h"
#include <QQUickItem>
#include <QModelIndex>

PageNewHero::PageNewHero()
    : m_selectedRace("")
    , m_selectedClass("")
{}

std::string PageNewHero::GetSelectedRace() const
{
    return m_selectedRace;
}

std::string PageNewHero::GetSelectedClass() const
{
    return m_selectedClass;
}

void PageNewHero::slotOnRaceSelected(int index)
{
    auto qmlPageNewHeroPtr = GetMapQmlCpp().at("Page_NewHero").QmlPtr;

    //////////////////////////////////// RACE MODEL DATA //////////////////////////////
    CMainMenuDataModel* raceModelData = qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("raceModelData"));

    if( raceModelData->at(index)->GetSelected() )
    {
        //This race has been already selected, so we unselect it.
        m_selectedRace = "";
        raceModelData->at(index)->SetColor("light green");
        raceModelData->at(index)->SetSelected(false);
    }
    else
    {
        m_selectedRace = raceModelData->at(index)->GetMenuText().toStdString();

        for(int i = 0; i < raceModelData->size(); i++)
        {
            raceModelData->at(i)->SetColor("light green");
            raceModelData->at(i)->SetSelected(false);
            raceModelData->update(i);
        }
        raceModelData->at(index)->SetColor("white");
        raceModelData->at(index)->SetSelected(true);
    }
    raceModelData->update(index);

    //////////////////////////////////// CLASS MODEL DATA //////////////////////////////
    CMainMenuDataModel* classModelData = qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("classModelData"));
    const auto& availableClasses = Dependencies::GetAvailableClasses( m_selectedRace );

    for(int i = 0; i < classModelData->size(); i++)
    {
        std::string className = classModelData->at(i)->GetMenuText().toStdString();
        auto iterRes = std::find(availableClasses.begin(), availableClasses.end(), className);
        if( iterRes != availableClasses.end())
        {
            classModelData->at(i)->SetColor("light green");
            classModelData->at(i)->SetEnabled(true);
        }
        else
        {
            classModelData->at(i)->SetColor("red");
            classModelData->at(i)->SetEnabled(false);
        }
        classModelData->at(i)->SetSelected(false);
        classModelData->update(i);
    }
}

void PageNewHero::slotOnClassSelected(int index)
{
    auto qmlPageNewHeroPtr = GetMapQmlCpp().at("Page_NewHero").QmlPtr;

    //////////////////////////////////// RACE MODEL DATA //////////////////////////////
    CMainMenuDataModel* classModelData = qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("classModelData"));

    if( classModelData->at(index)->GetSelected() )
    {
        //This class has been already selected, so we unselect it.
        m_selectedClass = "";
        classModelData->at(index)->SetColor("light green");
        classModelData->at(index)->SetSelected(false);
    }
    else
    {
        for(int i = 0; i < classModelData->size(); i++)
        {
            const char* color = classModelData->at(i)->GetEnabled() ?
                        "light green" : "red";
            classModelData->at(i)->SetColor(color);
            classModelData->at(i)->SetSelected(false);
            classModelData->update(i);
        }
        m_selectedRace = classModelData->at(index)->GetMenuText().toStdString();
        classModelData->at(index)->SetColor("white");
        classModelData->at(index)->SetSelected(true);
    }
    classModelData->update(index);
}

void PageNewHero::slotOnRaceInfoSelected(int index)
{
    auto qmlPageNewHeroPtr = GetMapQmlCpp().at("Page_NewHero").QmlPtr;
    CMainMenuDataModel* raceModelData = qobject_cast<CMainMenuDataModel*>(qmlPageNewHeroPtr->findChild<QObject*>("raceModelData"));
    std::string selectedRaceName = raceModelData->at(index)->GetMenuText().toStdString();

    QString selectedInfoText = Dependencies::GetInfoByRaceName(selectedRaceName).c_str();

    emit signalSetRaceInfo(selectedInfoText);
}

