import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwarehousepagecategorybridge 1.0

QIXScreenPage {
    id: qIXScreenPage
    title: qsTr("register")
    height: 1080
    contentHeight: 1080

    Component.onCompleted: {
        ixWarehousePageCategoryBridge.listModel = qIXGridView.model;
        ixWarehousePageCategoryBridge.feedModel();
    }

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

    IXWarehousePageCategoryBridge {
        id: ixWarehousePageCategoryBridge
    }

    QIXWarehousePageCategoryGrid {
        id: qIXGridView
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: rectangle.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.rightMargin: 40
        anchors.leftMargin: 40
        anchors.topMargin: 20
        bridge: ixWarehousePageCategoryBridge
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
    D{i:0;formeditorZoom:0.75}D{i:3}
}
##^##*/
