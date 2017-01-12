#ifndef QMLCPPCOORDINATOR_H
#define QMLCPPCOORDINATOR_H
#include <map>
#include <string>
#include <QQuickWindow>

class QQmlApplicationEngine;

class qmlCppObject
{
public:
    qmlCppObject();
    qmlCppObject(QObject* cppPtr, QQuickItem* qmlPtr);
    QObject* CppPtr;
    QQuickItem* QmlPtr;
};

void InitQmlCpp();
void LoadQmlConfigurations();
void ConnectSignals();

void SetVisiblePage(const std::string& pageName);

QQuickWindow* GetWindowPtr();
QQmlApplicationEngine* GetEnginePtr();
std::map<std::string, qmlCppObject>& GetMapQmlCpp();

#endif // QMLCPPCOORDINATOR_H
