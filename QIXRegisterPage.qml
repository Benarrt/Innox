import QtQuick 2.15

QIXScreenPage {
    id: qIXScreenPage
    title: qsTr("register")
    height: 1080
    contentHeight: 880

    QIXTextField {
        id: qIXTextField
        x: 260
        y: 210
        width: 650
        height: 50
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 20
        anchors.verticalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("email")
        text: ""
    }

    QIXTextField {
        id: qIXTextField1
        x: 250
        width: 650
        height: 50
        anchors.top: qIXTextField.bottom
        font.pointSize: 20
        anchors.topMargin: 20
        placeholderText: qsTr("haslo")
        anchors.horizontalCenter: parent.horizontalCenter
        echoMode: TextInput.Password
        text: ""
    }

    QIXTextField {
        id: qIXTextField2
        x: 250
        width: 650
        height: 50
        anchors.top: qIXTextField1.bottom
        font.pointSize: 20
        anchors.topMargin: 20
        echoMode: TextInput.Password
        placeholderText: qsTr("powtorz haslo")
        anchors.horizontalCenter: parent.horizontalCenter
        text: ""
    }

    QIXButton {
        id: qIXButton
        width: 300
        height: 60
        text: qsTr("Zarejestruj")
        anchors.top: qIXTextField2.bottom
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
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
    D{i:0;formeditorZoom:0.75}
}
##^##*/
