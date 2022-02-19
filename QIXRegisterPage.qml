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
        placeholderText: "haslo"
        anchors.horizontalCenter: parent.horizontalCenter
        echoMode: TextInput.Password
    }

    QIXTextField {
        id: qIXTextField2
        x: 250
        width: 400
        anchors.top: qIXTextField1.bottom
        horizontalAlignment: Text.AlignHCenter
        anchors.topMargin: 20
        echoMode: TextInput.Password
        placeholderText: "powtorz haslo"
        anchors.horizontalCenter: parent.horizontalCenter
    }

    QIXButton {
        id: qIXButton
        text: "Zarejestruj"
        anchors.left: qIXTextField1.left
        anchors.right: qIXTextField1.right
        anchors.top: qIXTextField2.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        display: AbstractButton.TextBesideIcon
        anchors.topMargin: 20

        onClicked: {
            ixloginscreen.registerAccount(qIXTextField.text, qIXTextField1.text);
        }
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
    D{i:0;formeditorZoom:0.75}D{i:8}
}
##^##*/
