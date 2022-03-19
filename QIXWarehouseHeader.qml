import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

Item {
    height: 80
    Rectangle {
        id: rectangle
        color: IXStyleSheet.mediumColor()
        anchors.fill: parent

        QIXLabel {
            width: 280
            height: 34
            text: qsTr("Dodaj albo usun twoje towary")
            anchors.top: rectangle1.bottom
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: rectangle1
            width: 186
            height: 36
            color: "#00FFFFFF"
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10

            QIXLabel {
                width: 89
                height: 36
                color: IXStyleSheet.superLightColor()
                text: qsTr("Magazyn")
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
                width: 75
                height: 36
                color: "#00ffffff"

                QIXLabel {
                    text: qsTr("Twoj")
                    anchors.fill: parent
                    font.pointSize: 20
                }
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}D{i:6}
}
##^##*/
