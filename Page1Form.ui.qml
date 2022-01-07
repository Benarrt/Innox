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
        id: rectangle
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
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 18
            placeholderText: qsTr("Tooltip")
        }

        QIXTextField {
            id: textField1
            x: 208
            width: 283
            height: 102
            anchors.top: textField.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 100
            placeholderText: qsTr("Tooltip")
            font.pointSize: 18
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
    D{i:0;formeditorZoom:0.33000001311302185}D{i:4}
}
##^##*/
