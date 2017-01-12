#include "PageNewHero.h"
#include "QmlCppCoordinator.h"
#include "Dependencies.h"
#include "QmlConfig.h"

PageNewHero::PageNewHero()
    : m_selectedRace("")
{

}

std::string PageNewHero::GetSelectedRace() const
{
    return m_selectedRace;
}

void PageNewHero::slotOnRaceSelected(QString selectedRace)
{
    m_selectedRace = selectedRace.toStdString();

    QVariantList availableClasses = Dependencies::GetAvailableClasses( m_selectedRace );

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
    QVariantList classesMap = fillVariantMap("class", availableClasses);
    setClasses(classesMap);
}

void PageNewHero::slotOnClassSelected(QString selectedClass)
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

    QVariantList abilities = {"When", "I", "Say", "Jump", "You", "Say", "How", "High"};
    QVariantList abilitiesMap = fillVariantMap("abilities", abilities);

    setAbilities( abilitiesMap );
}

void PageNewHero::setRaces(QVariant races)
{
    emit signalSetRaces( races );
}

void PageNewHero::setClasses(QVariant classes)
{
    emit signalSetClasses( classes );
}

void PageNewHero::setAbilities(QVariant abilities)
{
    emit signalSetAbilities( abilities );
}
