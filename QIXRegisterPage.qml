import QtQuick 2.15
import QtQuick.Controls 2.15

QIXScreenPage {
    id: qIXScreenPage
    title: qsTr("register")
    height: 1080
    contentHeight: 880

    QIXTextField {
        id: qIXTextField
        x: 260
        y: 210
        width: 400
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("email")
    }

    QIXTextField {
        id: qIXTextField1
        x: 250
        width: 400
        anchors.top: qIXTextField.bottom
        horizontalAlignment: Text.AlignHCenter
        anchors.topMargin: 20
        placeholderText: qsTr("haslo")
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
        placeholderText: qsTr("powtorz haslo")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    QIXButton {
        id: qIXButton
        text: qsTr("Zarejestruj")
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
