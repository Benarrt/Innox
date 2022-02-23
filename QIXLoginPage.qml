import QtQuick 2.15

QIXScreenPage {
    id: qIXScreenPage

    QIXTextField {
        id: qIXTextField
        x: 260
        width: 400
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("email")
        text: ""
    }

    QIXTextField {
        id: qIXTextField1
        x: 250
        width: 400
        anchors.top: qIXTextField.bottom
        anchors.topMargin: 20
        placeholderText: qsTr("haslo")
        anchors.horizontalCenter: parent.horizontalCenter
        echoMode: TextInput.Password
        text: ""
    }

    QIXButton {
        id: qIXButton
        width: 150
        height: 40
        text: qsTr("Zaloguj")
        anchors.left: qIXTextField1.left
        anchors.top: qIXTextField1.bottom
        anchors.leftMargin: 0
        anchors.topMargin: 20

        onClicked: {
            ixloginscreen.logIntoAccount(qIXTextField.text, qIXTextField1.text);
        }
    }

    QIXButton {
        id: qIXButton1
        width: 230
        height: 40
        text: qsTr("Zapomnialem hasla")
        anchors.right: qIXTextField1.right
        anchors.top: qIXTextField1.bottom
        anchors.rightMargin: 0
        anchors.topMargin: 20

        onClicked: {
            ixloginscreen.recoverAccountPassword(qIXTextField.text);
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
    D{i:0;formeditorZoom:0.75}
}
##^##*/
