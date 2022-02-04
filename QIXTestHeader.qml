import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    height: 100
    Rectangle {
        id: rectangle
        color: "#c82626"
        anchors.fill: parent
        Label {
            width: 280
            height: 60
            text: "LOGIN LABEL"
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 20
        }
    }
}


