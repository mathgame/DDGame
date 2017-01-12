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

///////////////////////////////// NAME INSERT FIELD ///////////////////////////
    Text
    {
        id: textName
        x: 173
        y: 109
        text: qsTr("Name: ")
        font.pixelSize: 18
    }

    Rectangle
    {
        x: 278
        y: 110
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
        Rectangle
        {
            width: grid.cellWidth;
            height: grid.cellHeight;
            color: "yellow";
            Text
            {
                text: modelData.race
                color: "black";
                font.pixelSize: 18
            }
        }
    }

    Text
    {
        id: raceClass
        x: 173
        y: 155
        text: qsTr("Race:")
        font.pixelSize: 18
    }

    GridView
    {
        id: gridRaces
        x: 278
        y: 155
        width: 800
        height: 100
        cellWidth: 150
        cellHeight: 25
        delegate: contactDelegateRace
    }

///////////////////////////////// CLASS FIELD ///////////////////////////
    Component
    {
        id: contactDelegateClass
        Rectangle
        {
            width: grid.cellWidth;
            height: grid.cellHeight;
            color: "red";
            Text
            {
                text: modelData.class
                color: "black";
                font.pixelSize: 18
            }
        }
    }

    Text
    {
        id: textClass
        x: 173
        y: 222
        text: qsTr("Class:")
        font.pixelSize: 18
    }

    GridView
    {
        id: gridClass
        x: 278
        y: 222
        width: 800
        height: 100
        cellWidth: 150
        cellHeight: 25
        delegate: contactDelegateClass
    }

///////////////////////////////// ABILITIES FIELD ///////////////////////////
    Component
    {
        id: contactDelegateAbilities
        Rectangle
        {
            width: grid.cellWidth;
            height: grid.cellHeight;
            color: "red";
            Text
            {
                text: modelData.abilities
                color: "black";
                font.pixelSize: 18
            }
        }
    }

    Text
    {
        id: textAbilities
        x: 173
        y: 288
        text: qsTr("Abilities:")
        font.pixelSize: 18
    }

    GridView
    {
        id: gridAbilities
        x: 278
        y: 288
        width: 800
        height: 100
        cellWidth: 150
        cellHeight: 25
        delegate: contactDelegateAbilities
    }
}
