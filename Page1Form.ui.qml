import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 720
    height: 1280

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Rectangle {
        width: 720
        height: 1280
        color: "#f07171"
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }
}
