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

    RowLayout {
        anchors.top: qIXTextField.bottom
        anchors.topMargin: 20
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

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
