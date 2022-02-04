import QtQuick 2.15
import QtQuick.Controls 2.15

QIXScreenPage {
    id: qIXScreenPage
    title: "register"
    height: 1080
    contentHeight: 880

    background: Rectangle {
        color: "#29323c"
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#29323c"
            }

            GradientStop {
                position: 1
                color: "#485563"
            }
        }
    }

    footer: QIXPageIndicatorFooter {

    }

    header: QIXTestHeader {

    }

    QIXTextField {
        id: qIXTextField
        x: 260
        y: 210
        width: 400
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: "email"
    }

    QIXTextField {
        id: qIXTextField1
        x: 250
        width: 400
        anchors.top: qIXTextField.bottom
        horizontalAlignment: Text.AlignHCenter
        anchors.topMargin: 20
        placeholderText: "password"
        anchors.horizontalCenter: parent.horizontalCenter
        echoMode: TextInput.Password
    }

    QIXButton {
        id: qIXButton
        width: 150
        text: "Zaloguj"
        anchors.left: qIXTextField1.left
        anchors.top: qIXTextField1.bottom
        anchors.leftMargin: 0
        display: AbstractButton.TextBesideIcon
        anchors.topMargin: 20
    }

    QIXButton {
        id: qIXButton1
        width: 200
        height: 40
        text: "Zapomnialem hasla"
        anchors.right: qIXTextField1.right
        anchors.top: qIXTextField1.bottom
        anchors.rightMargin: 0
        anchors.topMargin: 20
        display: AbstractButton.TextBesideIcon
    }




    /*header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    footer: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }*/
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:2}
}
##^##*/
