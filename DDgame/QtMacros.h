#ifndef QTMACROS_H
#define QTMACROS_H
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlFile>

#define CREATE_QML_OBJECT(__obj__, __url__, __eng__, __parent__) \
{\
    QQmlComponent component((__eng__), (__url__), (__parent__));\
    if (component.status() == QQmlComponent::Ready ) {\
        __obj__ = component.create(__eng__->rootContext());\
        if ( __obj__ ) {\
            QQmlEngine::setObjectOwnership(__obj__, QQmlEngine::CppOwnership);\
            QQuickItem * ptr = qobject_cast<QQuickItem *>(__parent__);\
            if ( ptr ) {\
                __obj__->setParent(__parent__);\
                qobject_cast<QQuickItem *>(__obj__)->setParentItem( ptr );\
            }\
        }\
    } else {\
        qDebug() << component.errorString();\
    }\
}

#endif // QTMACROS_H
