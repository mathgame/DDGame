#include "Dependencies.h"
#include "QmlConfig.h"
#include "QmlCppCoordinator.h"
#include <QDebug>

// TODO CREATE DEPENDECIES FROM XML
std::map<std::string, QVariantList> mapRacesToClass =
{
    { "Human",      {QmlConfig::classes} },
    { "Orc",        {QVariantList{"Warrior", "Archer"}} },
    { "Elf",        {QmlConfig::classes} },
    { "Dwarf",      {QVariantList{"Warrior", "Elder", "Paladin"}}},
    { "Dark Elf",   {QmlConfig::classes} },
};

QVariantList Dependencies::GetAvailableClasses(const std::string &raceName)
{
    auto iter = mapRacesToClass.find(raceName);
    if( iter == mapRacesToClass.end() )
    {
        qDebug() << "Warning: Trying to get available classes from race that doesnt exist";
        return QVariantList();
    }
    return iter->second;
}
