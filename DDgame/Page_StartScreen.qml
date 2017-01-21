import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.2

Rectangle
{
    id: pageStartScreenID
    width: 1280
    height: 960

    signal signalSingleplayer()
    signal signalMultiplayer()

    Button
    {
        id: buttonSinglePlayer
        x: 436
        y: 251
        width: 344
        height: 87
        text: qsTr("New Game")
        style: ButtonStyle {
          label: Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            text: control.text
          }
        }
        onClicked:
        {
            signalSingleplayer()
        }
    }

    Button
    {
        id: buttonMultiplayer
        x: 436
        y: 375
        width: 344
        height: 82
        text: qsTr("Multiplayer")
        style: ButtonStyle {
          label: Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            text: control.text
          }
        }
        onClicked:
        {
            signalMultiplayer()
        }
    }

    Button {
        id: buttonSettings
        x: 436
        y: 509
        width: 344
        height: 87
        text: qsTr("Settings")
        style: ButtonStyle {
          label: Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            text: control.text
          }
        }
    }

    Button
    {
        id: buttonQuit
        x: 436
        y: 649
        width: 344
        height: 87
        text: qsTr("Quit")
        style: ButtonStyle
        {
          label: Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            text: control.text
          }
        }
        //onClicked: Qt.quit()
    }
}
