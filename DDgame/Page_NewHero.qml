import QtQuick 2.0

Rectangle
{
    id: pageNewHeroId
    width: 1280
    height: 960
    color: "#fefee6"

    signal signalSetRaces( var races )
    onSignalSetRaces:
    {
        gridRaces.model = races
    }

    signal signalSetClasses( var classes )
    onSignalSetClasses:
    {
        gridClass.model = classes
    }

    signal signalSetAbilities( var abilities )
    onSignalSetAbilities:
    {
        gridAbilities.model = abilities
    }

    signal signalOnClassSelect( string selectedClass )
    signal signalOnRaceSelect( string selectedRace )
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
                color: "light green"
                Text
                {
                    anchors.centerIn: parent
                    text: modelData.race
                    color: "black";
                    font.pixelSize: 18
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        console.log( modelData.race )
                        signalOnRaceSelect( modelData.race )
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
        width: 756
        height: 100
        cellWidth: 150
        cellHeight: 25
        delegate: contactDelegateRace
    }

///////////////////////////////// CLASS FIELD ///////////////////////////
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
                color: "red"
                Text
                {
                    anchors.centerIn: parent
                    text: modelData.class
                    color: "black";
                    font.pixelSize: 18
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        console.log( modelData.class )
                        signalOnClassSelect( modelData.class )
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
        width: 756
        height: 100
        cellWidth: 150
        cellHeight: 25
        delegate: contactDelegateClass
    }

///////////////////////////////// ABILITIES FIELD ///////////////////////////
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
                color: "green"
                Text
                {
                    anchors.centerIn: parent
                    text: modelData.abilities
                    color: "black";
                    font.pixelSize: 18
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
        width: 756
        height: 100
        cellWidth: 150
        cellHeight: 25
        delegate: contactDelegateAbilities
    }
}
