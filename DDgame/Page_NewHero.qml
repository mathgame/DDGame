import QtQuick 2.0
import models 1.0

Rectangle
{
    id: pageNewHeroId
    width: 1280
    height: 960
    color: "#fefee6"

    property alias selectedInfoText: textInfoField.text

    signal signalOnRaceSelect(int index)
    signal signalOnClassSelect(int index)

    signal signalOnRaceInfoSelect(int index)
    signal signalSetRaceInfo(string selectedInfoRace)
    onSignalSetRaceInfo:
    {
        pageNewHeroId.selectedInfoText = selectedInfoRace
    }

///////////////////////////////// NAME INSERT FIELD ///////////////////////////
    Text
    {
        id: textName
        x: 129
        y: 83
        text: qsTr("Name: ")
        font.pixelSize: 18
    }

    Rectangle
    {
        x: 234
        y: 84
        width: 165
        height: 20
        color: "#f0d3d3"
        TextInput
        {
            id: textInputName
            maximumLength : 15
            x: 5
            width: 165
            height: 20
            font.pixelSize: 18
        }
    }

///////////////////////////////// RACE FIELD ///////////////////////////
    CMainMenuDataModel
    {
        id: raceModelData
        objectName: "raceModelData"
    }

    Component
    {
        id: contactDelegateRace
        Item
        {
            width: gridRaces.cellWidth;
            height: gridRaces.cellHeight;
            Rectangle
            {
                anchors.fill: parent
                anchors.rightMargin: 5
                anchors.topMargin: 5
                enabled: model.bEnabled
                color: model.sColor
                Text
                {
                    anchors.centerIn: parent
                    text: model.sMenuText
                    color: "black";
                    font.pixelSize: 18
                }
                MouseArea
                {
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    anchors.fill: parent
                    onClicked:
                    {
                        if(mouse.button & Qt.LeftButton)
                        {
                            signalOnRaceSelect(index)
                        }
                        if(mouse.button & Qt.RightButton)
                        {
                            console.log("right button clicked")
                            signalOnRaceInfoSelect(index)
                        }
                    }

                }
            }
        }
    }

    Text
    {
        id: textRace
        x: 129
        y: 129
        text: qsTr("Race:")
        font.pixelSize: 18
    }

    GridView
    {
        id: gridRaces
        x: 234
        y: 129
        width: 650
        height: 100
        cellWidth: 150
        cellHeight: 25
        model: raceModelData
        delegate: contactDelegateRace
    }

///////////////////////////////// CLASS FIELD ///////////////////////////
    CMainMenuDataModel
    {
        id: classModelData
        objectName: "classModelData"
    }

    Component
    {
        id: contactDelegateClass
        Item
        {
            width: gridClass.cellWidth;
            height: gridClass.cellHeight;
            Rectangle
            {
                anchors.fill: parent
                anchors.rightMargin: 5
                anchors.topMargin: 5
                enabled: model.bEnabled
                color: model.sColor
                Text
                {
                    anchors.centerIn: parent
                    text: model.sMenuText
                    color: "black";
                    font.pixelSize: 18
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                         signalOnClassSelect(index)
                    }
                }
            }
        }
    }

    Text
    {
        id: textClass
        x: 129
        y: 243
        text: qsTr("Class:")
        font.pixelSize: 18
    }

    GridView
    {
        id: gridClass

        x: 234
        y: 243
        width: 650
        height: 100
        cellWidth: 150
        cellHeight: 25
        model: classModelData
        delegate: contactDelegateClass
    }

/////////////////////////////////// ABILITIES FIELD ///////////////////////////
    CMainMenuDataModel
    {
        id: abilitiesModelData
        objectName: "abilitiesModelData"
    }

    Component
    {
        id: contactDelegateAbilities
        Item
        {
            width: gridClass.cellWidth;
            height: gridClass.cellHeight;
            Rectangle
            {
                anchors.fill: parent
                anchors.rightMargin: 5
                anchors.topMargin: 5
                enabled: model.bEnabled
                color: model.sColor
                Text
                {
                    anchors.centerIn: parent
                    text:  model.sMenuText
                    color: "black";
                    font.pixelSize: 18
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        console.log( "abilities clicked" )
                    }
                }
            }
        }
    }

    Text
    {
        id: textAbilities
        x: 129
        y: 359
        text: qsTr("Abilities:")
        font.pixelSize: 18
    }

    GridView
    {
        id: gridAbilities
        x: 234
        y: 359
        width: 650
        height: 150
        cellWidth: 150
        cellHeight: 25
        model: abilitiesModelData
        delegate: contactDelegateAbilities
    }

    /////////////////////////////////// INFO FIELD ///////////////////////////

    Rectangle
    {
        x: 929
        y: 129
        width: 300
        height: 380
        color: "yellow"
        Text
        {
            id: textInfoField
            anchors.fill: parent
            anchors.topMargin: 20
            anchors.bottomMargin: 10
            anchors.leftMargin: 20
            anchors.rightMargin: 10

            color: "black"
            font.pointSize:16
            wrapMode: Text.Wrap
            text: ""
        }
    }
}





