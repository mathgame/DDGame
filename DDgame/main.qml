import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow
{
    id: appWindow
    objectName: "appWindowObject"
    title: qsTr("Application Window")
    visible: true
    width: 1280
    height: 960

    Rectangle
    {
        objectName: "viewContainer"
        anchors.fill: parent
        color: "blue"
    }
}
