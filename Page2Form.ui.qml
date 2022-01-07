import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    id: page
    width: 720
    height: 1280

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Rectangle {
        id: rectangle
        width: 720
        height: 1280
        color: "#29f88c"

        QIXTextField {
            id: qIXTextField
            x: 243
            y: 226
            width: 234
            height: 100
        }

        QIXTextField {
            id: qIXTextField1
            x: 243
            width: 234
            height: 100
            anchors.top: qIXTextField.bottom
            anchors.topMargin: 100
        }
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}D{i:4}
}
##^##*/
