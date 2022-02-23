import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    height: 80
    Rectangle {
        id: rectangle
        color: "#8fb9a8"
        anchors.fill: parent

        QIXLabel {
            width: 280
            height: 34
            color: "#ffffff"
            text: qsTr("Zaloguj sie lub zaloz nowe konto")
            anchors.top: rectangle1.bottom
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: rectangle1
            width: 186
            height: 36
            color: "#00000000"
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10

            QIXLabel {
                width: 89
                height: 36
                color: "#fefad4"
                text: qsTr("Innox!")
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: rectangle2.right
                font.bold: true
                anchors.leftMargin: 15
                font.pointSize: 20
            }

            Rectangle {
                id: rectangle2
                x: 0
                y: 0
                width: 97
                height: 36
                color: "#00ffffff"

                QIXLabel {
                    width: 95
                    height: 36
                    text: qsTr("Witaj w")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pointSize: 20
                }
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/
