import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Rectangle
{
    id: pageStartScreenID
    width: 1280
    height: 960

    signal signalNewGame()
    signal signalLoadGame()

    Button
    {
        id: buttonNewGame
        x: 438
        y: 280
        width: 404
        height: 129
        text: qsTr("New Game")
        onClicked:
        {
            signalNewGame()
        }
    }

    Button
    {
        id: buttonLoadGame
        x: 438
        y: 489
        width: 404
        height: 129
        text: qsTr("Load Game")
        onClicked:
        {
            signalLoadGame()
        }
    }
}
