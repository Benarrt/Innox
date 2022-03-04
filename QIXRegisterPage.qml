import QtQuick 2.15

QIXScreenPage {
    id: qIXScreenPage
    title: qsTr("register")
    height: 1080
    contentHeight: 880

    Connections {
        target: ixloginscreen
        function onValidRegister() {

        }

        function onInvalidRegister(error) {
            qIXMessageBoard.clear()
            if(error === 3033) {
                qIXMessageBoard.addText(3033, qsTr("Istnieje juz konto z podanym adresem email"));
            } else {
                qIXMessageBoard.addText(3040, qsTr("Podany email jest nieprawidlowy"));
            }
        }
    }

    QIXEmailInput {
        id: qIXTextField
        x: 260
        y: 210
        width: 650
        height: 50
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 20
        anchors.verticalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        text: ""
    }

    QIXPasswordInput {
        id: qIXTextField1
        x: 250
        width: 650
        height: 50
        anchors.top: qIXTextField.bottom
        font.pointSize: 20
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
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
            qIXMessageBoard.clear()
            if(!qIXTextField.text.length || !qIXTextField.logic.veryfiEmail())
            {
                qIXMessageBoard.addText(3040, qsTr("Podany email jest nieprawidlowy"));
                return;
            }

            if(qIXTextField1.text != qIXTextField2.text)
            {
                qIXMessageBoard.addText(4, qsTr("Podane hasla musza byc identyczne"));
                return;
            }

            var passwordErrors = qIXTextField1.logic.veryfiPassword();
            console.log(passwordErrors);
            if(passwordErrors.length)
            {
                for(var pwError of passwordErrors) {
                    if(pwError === 0) {
                        qIXMessageBoard.addText(0, qsTr("Haslo musi miec conjamniej 8 znakow"));
                    }

                    if(pwError === 1) {
                        qIXMessageBoard.addText(1, qsTr("Haslo musi miec conjamniej 1 duza litere"));
                    }

                    if(pwError === 2) {
                        qIXMessageBoard.addText(2, qsTr("Haslo musi miec conjamniej 1 cyfre"));
                    }

                    if(pwError === 3) {
                        qIXMessageBoard.addText(3, qsTr("Haslo musi miec conjamniej 1 znak specjalny"));
                    }
                }

                return;
            }
            ixloginscreen.registerAccount(qIXTextField.text, qIXTextField1.text);
        }
    }

    QIXMessageBoard {
        id: qIXMessageBoard
        width: 650
        anchors.bottom: qIXTextField.top
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
