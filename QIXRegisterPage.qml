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
            qIXRegisterErrors.reset();
            console.log(error);
            if(error === 3033) {
                qIXRegisterErrors.duplicatedEmail = true;
            } else {
                qIXRegisterErrors.invalidEmail = true;
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
        anchors.top: qIXRegisterErrors.bottom
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10

        onClicked: {
            qIXRegisterErrors.reset()
            if(!qIXTextField.text.length || !qIXTextField.logic.veryfiEmail())
            {
                qIXRegisterErrors.invalidEmail = true;
                return;
            }

            if(qIXTextField1.text != qIXTextField2.text)
            {
                qIXRegisterErrors.notEqual = true;
                return;
            }

            var passwordErrors = qIXTextField1.logic.veryfiPassword();
            console.log(passwordErrors);
            if(passwordErrors.length)
            {
                for(var pwError of passwordErrors) {
                    if(pwError === 0)
                        qIXRegisterErrors.tooShort = true;

                    if(pwError === 1)
                        qIXRegisterErrors.noUpper = true;

                    if(pwError === 2)
                        qIXRegisterErrors.noNumber = true;

                    if(pwError === 3)
                        qIXRegisterErrors.noSpecial = true;
                }

                return;
            }
            ixloginscreen.registerAccount(qIXTextField.text, qIXTextField1.text);
        }
    }

    QIXRegisterErrors {
        id: qIXRegisterErrors
        anchors.top: qIXTextField2.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
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
