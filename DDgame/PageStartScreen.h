#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QObject>
#include <QDebug>
#include "QmlCppCoordinator.h"

class PageStartScreen : public QObject
{
    Q_OBJECT
public slots:
    void slotSingleplayer();
    void slotMultiplayer();

public:
    PageStartScreen();
    QQmlApplicationEngine* Engine;
    QObject* ViewContainer;
};

#endif // STARTSCREEN_H
