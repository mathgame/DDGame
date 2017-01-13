#ifndef QMLCONFIG_H
#define QMLCONFIG_H

#include <vector>
#include <string>

//TODO READ FROM CONFIG FILE - XML
namespace QmlConfig
{
    static const std::vector<std::string> races = {"Human", "Orc", "Elf", "Dwarf", "Dark Elf"};

    static const std::vector<std::string> classes = {"Paladin", "Warrior", "Archer",
            "Magician", "Druid", "Rogue", "Priest", "Warlock", "Elder"};

    static const std::vector<std::string> abilities = {"Power Shot", "Power Arrow", "Power Ice",
                "Power Fire", "LOL", "IMBA", "DONT PICK ME", "Newbie", "Trash",
                "Ultimate", "Electricity", "Fire", "Ice", "Dawn", "Dog",
                "Cat", "Dummy", "Word", "Hunger", "Col", "Reel", "Heart",
                "Sun", "Kiss", "Love"};
}

#endif // QMLCONFIG_H
