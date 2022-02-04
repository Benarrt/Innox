import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    height: 100
    Rectangle {
        id: rectangle
        color: "#c82626"
        anchors.fill: parent
        QIXPageIndicator {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            count: 5
            currentIndex: 2
            font.pointSize: 16
        }
    }
}
