#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H
#include <string>
#include <QVariantList>

namespace Dependencies
{
    std::vector<std::string> GetAvailableClasses(const std::string& raceName);
    std::string GetInfoByRaceName(const std::string raceName);
}

#endif // DEPENDENCIES_H
