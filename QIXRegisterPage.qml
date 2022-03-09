import QtQuick 2.15

QIXScreenPage {
    id: qIXScreenPage
    title: qsTr("register")
    height: 1080
    contentHeight: 880

    Connections {
        target: ixloginscreen
        function onValidRegister() {
            qIXButton.enabled = true;
            qIXRegisterMessages.clear();
            qIXRegisterMessages.addMessage(qIXRegisterMessages.registerSuccess)
        }

        function onInvalidRegister(error) {
            qIXButton.enabled = true;
            qIXRegisterMessages.clear();
            if(error === 3033) {
                qIXRegisterErrors.addMessage(qIXRegisterErrors.duplicatedEmail);
            } else if(error === 3040) {
                qIXRegisterErrors.addMessage(qIXRegisterErrors.invalidEmail);
            } else {
                qIXRegisterErrors.addMessage(qIXRegisterErrors.unknownError);
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
            qIXRegisterErrors.clear();
            qIXRegisterMessages.clear();
            if(!qIXTextField.text.length || !qIXTextField.logic.veryfiEmail())
            {
                qIXRegisterErrors.addMessage(qIXRegisterErrors.invalidEmail);
                return;
            }

            if(qIXTextField1.text != qIXTextField2.text)
            {
                qIXRegisterErrors.addMessage(qIXRegisterErrors.notEqualPws);
                return;
            }

            var passwordErrors = qIXTextField1.logic.veryfiPassword();
            console.log(passwordErrors);
            if(passwordErrors.length)
            {
                qIXRegisterErrors.addMessages(passwordErrors);
                return;
            }

            qIXButton.enabled = false;
            qIXRegisterMessages.addMessage(qIXRegisterMessages.registerInProgress)
            ixloginscreen.registerAccount(qIXTextField.text, qIXTextField1.text);
        }
    }

    QIXRegisterErrors {
        id: qIXRegisterErrors
        width: 650
        anchors.bottom: qIXTextField.top
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    QIXRegisterMessages {
        id: qIXRegisterMessages
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
