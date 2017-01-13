#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H
#include <string>
#include <QVariantList>

namespace Dependencies
{
    QVariantList GetAvailableClasses(const std::string& raceName);
}

#endif // DEPENDENCIES_H
