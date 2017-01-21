#include "PageStartScreen.h"

PageStartScreen::PageStartScreen()
    : Engine(nullptr)
    , ViewContainer(nullptr)
{

}

void PageStartScreen::slotSingleplayer()
{
    SetVisiblePage("Page_NewHero");
}

void PageStartScreen::slotMultiplayer()
{
    qDebug() << "Print from C++  void cppLoadGameSlot()";
}



