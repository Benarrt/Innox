import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    anchors.fill: parent
    Rectangle {
        id: rectangle
        color: "#c82626"
        anchors.fill: parent
        QIXPageIndicator {
            anchors.fill: parent
            font.pointSize: 16
        }
    }
}
