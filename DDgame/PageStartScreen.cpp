#include "PageStartScreen.h"

PageStartScreen::PageStartScreen()
    : Engine(nullptr)
    , ViewContainer(nullptr)
{

}

void PageStartScreen::slotNewGame()
{
    SetVisiblePage("Page_NewHero");
}

void PageStartScreen::slotLoadGame()
{
    qDebug() << "Print from C++  void cppLoadGameSlot()";
}



