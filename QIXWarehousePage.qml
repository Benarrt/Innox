import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

QIXScreenPage {
    id: qIXScreenPage
    title: qsTr("register")
    height: 1080
    contentHeight: 1080

    header: QIXWarehouseHeader {

    }

    QIXTextField {
        id: qIXTextField
        x: 260
        width: 650
        height: 50
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: ""
        anchors.top: parent.top
        anchors.topMargin: 50
        placeholderText: "Wyszukaj"
    }

    QIXGridView {
        id: qIXGridView
        height: 600
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: rectangle.bottom
        anchors.rightMargin: 40
        anchors.leftMargin: 40
        anchors.topMargin: 20
    }

    Rectangle {
        id: rectangle
        x: 188
        width: 430
        height: 40
        color: "#00ffffff"
        anchors.top: qIXTextField.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        RowLayout {
            x: 4
            y: -80
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            QIXRadioButton {
                checked: true
                text: qsTr("Dodane")
            }
            QIXRadioButton {
                text: qsTr("Nie dodane")
            }
            QIXRadioButton {
                text: qsTr("Wszystkie")
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:3}D{i:4}
}
##^##*/