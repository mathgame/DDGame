TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    PageNewHero.cpp \
    PageStartScreen.cpp \
    QmlCppCoordinator.cpp \
    Dependencies.cpp \
    GridViewComponent.cpp \
    ViewModel/MainMenuDataModel.cpp \
    ViewModel/MainMenuItem.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=

HEADERS += \
    QtMacros.h \
    PageNewHero.h \
    PageStartScreen.h \
    QmlCppCoordinator.h \
    QmlConfig.h \
    Dependencies.h \
    GridViewComponent.h \
    ViewModel/MainMenuDataModel.h \
    ViewModel/MainMenuItem.h
