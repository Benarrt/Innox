import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixdealerscreenheader 1.0

Item {
    height: 80
    property var logic: iXDealerScreenHeader

    Rectangle {
        id: rectangle
        color: IXStyleSheet.mediumColor()
        anchors.fill: parent

        QIXLabel {
            width: 280
            height: 34
            text: qsTr("...")
            anchors.top: rectangle1.bottom
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: rectangle1
            width: 255
            height: 36
            color: "#00FFFFFF"
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10

            QIXLabel {
                width: 165
                height: 36
                color: IXStyleSheet.superLightColor()
                text: qsTr("Uzytkownika")
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: rectangle2.right
                font.bold: true
                anchors.leftMargin: 5
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
                    text: qsTr("Panel")
                    anchors.fill: parent
                    font.pointSize: 20
                }
            }
        }

        QIXButton {
            id: qIXButton
            x: 490
            y: 14
            width: 100
            height: 40
            text: "Wyloguj"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 50

            onClicked: {
                iXDealerScreenHeader.logOut();
            }
        }

        IXDealerScreenHeader {
            id: iXDealerScreenHeader
            component: parent
        }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/
