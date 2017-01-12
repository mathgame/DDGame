#include "PageNewHero.h"

PageNewHero::PageNewHero()
{

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
