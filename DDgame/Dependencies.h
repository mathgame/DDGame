#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H
#include <string>
#include <QVariantList>

namespace Dependencies
{
    std::vector<std::string> GetAvailableClasses(const std::string& raceName);
    std::string GetInfoBySelectedField(const std::string fieldName);
}

#endif // DEPENDENCIES_H
