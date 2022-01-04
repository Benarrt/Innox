import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 720
    height: 1280
    clip: true

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Rectangle {
        width: 720
        height: 1280
        color: "#f07171"

        QIXTextField {
            id: textField
            x: 208
            y: 128
            width: 283
            height: 102
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 18
            placeholderText: qsTr("Tooltip")
        }
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

    footer: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.6600000262260437}
}
##^##*/

