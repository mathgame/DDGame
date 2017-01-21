#include "Dependencies.h"
#include "QmlConfig.h"
#include "QmlCppCoordinator.h"
#include <QDebug>

// TODO CREATE DEPENDECIES FROM XML
//std::map<std::string, std::vector<std::string>> mapRacesToClass =
//{
//    { "Human",      {QmlConfig::classes} },
//    { "Orc",        {std::vector<std::string>{"Warrior", "Archer"}} },
//    { "Elf",        {QmlConfig::classes} },
//    { "Dwarf",      {std::vector<std::string>{"Warrior", "Elder", "Paladin"}}},
//    { "Dark Elf",   {QmlConfig::classes} },
//};

//std::vector<std::string> CollectionOfWarriorClass =
//{
//    "Fighter", "Ranger", "Paladin"
//};

//std::vector<std::string> CollectionOfRoguefClass =
//{
//    "Thief", "Bard"
//};

//std::vector<std::string> CollectionOfClericClass =
//{
//    "Priest", "Druid"
//};

//std::vector<std::string> CollectionOfMageClass =
//{
//    "Wizard", "Sorceress"
//};

std::map<std::string, std::vector<std::string>> CollectionOfRaceClass =
{
    {"Human", {"Fighter", "Ranger", "Paladin", "Thief", "Bard", "Priest", "Druid", "Wizard", "Sorceress"}},
    {"Half Orc", {"Fighter", "Ranger", "Priest", "Druid", "Sorceress"}},
    {"Dwarf", {"Fighter", "Ranger", "Thief", "Bard", "Priest"}},
    {"Elf", {"Fighter", "Ranger", "Thief", "Bard", "Druid", "Wizard", "Sorceress"}},
};

std::map<std::string, std::vector<std::string>> ClassToFeatsDependencies =
{
      {"Fighter",   {"WarriorFeats"}},
      {"Ranger",    {"WarriorFeats", "DivineDruid"}},
      {"Paladin",   {"WarriorFeats", "DivinePriest"}},
      {"Thief",     {"Rogue"}},
      {"Bard",      {"Rogue", "ArcaneWizard"}},
      {"Priest",    {"WarriorFeats", "DivinePriest"}},
      {"Druid",     {"WarriorFeats", "DivineDruid"}},
      {"Wizard",    {"ArcaneWizard"}},
      {"Sorceress", {"ArcaneSorceress"}},
};

std::map<std::string, std::vector<std::string>> CollectionOfWarriorFeats =
{
    {"WeaponProficiencyMartial", {"allow usage of Martial and Simple weapons without penalty"}},
    {"ArmorProficiencyLeather", {"allow usageof Leather type of armor"}},
    {"ArmorProficiencyMail", {"allow usage of Mail type of armor"}},
    {"ShieldProficiencySmall", {"allow usage of Small shields"}},
    {"ShieldProficiencyLarge", {"allow usage of Large shields"}},
    {"HelmetProficiency", {"allow usage of helmets"}},
    {"Toughtness", { "gain extra hit point per level"}},
    {"Power Attack", {"on activation character lose 4 to hit chance in exchange for 5 extra points of damage"}},
    {"Cleave", {"after a death blow the character can hit enemy standing nearby"}},
};

std::map<std::string, std::vector<std::string>> CollectionOfRogueFeats =
{
    {"WeaponProficiencySimple", {"allow usage of Simple weapons without penalty"}},
    {"ArmorProficiencyLeather", {"allow usageof Leather type of armor"}},
    {"ShieldProficiencySmall", {"allow usage of Small shields"}},
    {"Pick Pocket", { "gain extra hit point per level"}},
    {"Hide in Shadows", {"on activation character lose 4 to hit chance in exchange for 5 extra points of damage"}},
    {"Backstab", {"after a death blow the character can hit enemy standing nearby"}},
    {"Disarm Trap", {"after a death blow the character can hit enemy standing nearby"}},
    {"Tumble", {"after a death blow the character can hit enemy standing nearby"}},
};

std::vector<std::string> Dependencies::GetAvailableClasses(const std::string &raceName)
{
    auto iter = CollectionOfRaceClass.find(raceName);
    if( iter == CollectionOfRaceClass.end() )
    {
        qDebug() << "Warning: Trying to get available classes from race that doesnt exist";
        return std::vector<std::string>();
    }
    return iter->second;
}

std::string Dependencies::GetInfoBySelectedField(const std::string fieldName)
{
    std::map<std::string, std::string> fieldInfos =
    {
        { "Human",      "HUMAN \n\n I'm human i have all classes available and im the imba race !" },
        { "Orc",        "ORC \n\n I'm orc and i am fighter by nature !" },
        { "Elf",        "ELF \n\n I'm elf :) !" },
        { "Dwarf",      "DWARF \n\n I'm dwarf and i am fat !" },
        { "Dark Elf",   "DARK ELF \n\n I'm dark elf i have all classes available and im the imba race + i can eat humans ^_^ !" },
    };

    auto iter = fieldInfos.find(fieldName);
    if( iter == fieldInfos.end() )
    {
        return std::string("NOT INITIALIZED INFO :)");
    }
    return iter->second;
}
