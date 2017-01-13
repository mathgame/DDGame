#include "Dependencies.h"
#include "QmlConfig.h"
#include "QmlCppCoordinator.h"
#include <QDebug>

// TODO CREATE DEPENDECIES FROM XML
std::map<std::string, std::vector<std::string>> mapRacesToClass =
{
    { "Human",      {QmlConfig::classes} },
    { "Orc",        {std::vector<std::string>{"Warrior", "Archer"}} },
    { "Elf",        {QmlConfig::classes} },
    { "Dwarf",      {std::vector<std::string>{"Warrior", "Elder", "Paladin"}}},
    { "Dark Elf",   {QmlConfig::classes} },
};

std::vector<std::string> Dependencies::GetAvailableClasses(const std::string &raceName)
{
    auto iter = mapRacesToClass.find(raceName);
    if( iter == mapRacesToClass.end() )
    {
        qDebug() << "Warning: Trying to get available classes from race that doesnt exist";
        return std::vector<std::string>();
    }
    return iter->second;
}

std::string Dependencies::GetInfoByRaceName(const std::string raceName)
{
    std::map<std::string, std::string> raceInfo =
    {
        { "Human",      "HUMAN \n\n I'm human i have all classes available and im the imba race !" },
        { "Orc",        "ORC \n\n I'm orc and i am fighter by nature !" },
        { "Elf",        "ELF \n\n I'm elf :) !" },
        { "Dwarf",      "DWARF \n\n I'm dwarf and i am fat !" },
        { "Dark Elf",   "DARK ELF \n\n I'm dark elf i have all classes available and im the imba race + i cant eat humans ^_^ !" },
    };

    auto iter = raceInfo.find(raceName);
    if( iter == raceInfo.end() )
    {
        qDebug() << "Warning: Trying to get available classes from race that doesnt exist";
        return "";
    }
    return iter->second;
}
