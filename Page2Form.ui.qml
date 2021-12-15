import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 720
    height: 1280

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Rectangle {
        width: 720
        height: 1280
        color: "#29f88c"
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}
