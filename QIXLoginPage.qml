import QtQuick 2.15

QIXScreenPage {
    id: qIXScreenPage

    Connections {
        target: ixloginscreen
        function onValidLogin() {
            qIXButton.enabled = true;
        }

        function onInvalidLogin(error) {
            qIXButton.enabled = true;
            qIXLoginErrors.addMessage(qIXLoginErrors.loginFailed);
        }

        function onValidPWRecover() {
            qIXButton1.enabled = true;
            qIXPasswordRecoverMsg.addMessage(qIXPasswordRecoverMsg.recoverSucces);
        }

        function onInvalidPWRecover(error) {
            qIXButton1.enabled = true;
            qIXPasswordRecoverErrors.addMessage(qIXPasswordRecoverErrors.recoverFailed);
        }
    }

    QIXEmailInput {
        id: qIXTextField
        x: 260
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
        anchors.topMargin: 20
        placeholderText: qsTr("haslo")
        anchors.horizontalCenter: parent.horizontalCenter
        text: ""
        font.pointSize: 20
    }

    QIXButton {
        id: qIXButton
        width: 275
        height: 60
        text: qsTr("Zaloguj")
        anchors.left: qIXTextField1.left
        anchors.top: qIXTextField1.bottom
        font.pointSize: 20
        anchors.leftMargin: 0
        anchors.topMargin: 20

        onClicked: {
            qIXLoginErrors.clear();
            qIXPasswordRecoverErrors.clear();
            qIXPasswordRecoverMsg.clear();
            if(!qIXTextField.text.length || !qIXTextField.logic.veryfiEmail()) {
                qIXLoginErrors.addMessage(qIXLoginErrors.invalidEmail);
                return;
            }

            if(!qIXTextField1.text.length) {
                qIXLoginErrors.addMessage(qIXLoginErrors.invalidPassword);
                return;
            }

            qIXButton.enabled = false;
            ixloginscreen.logIntoAccount(qIXTextField.text, qIXTextField1.text);
        }
    }

    QIXButton {
        id: qIXButton1
        width: 355
        height: 60
        text: qsTr("Zapomnialem hasla")
        anchors.right: qIXTextField1.right
        anchors.top: qIXTextField1.bottom
        font.pointSize: 20
        anchors.rightMargin: 0
        anchors.topMargin: 20

        onClicked: {
            qIXLoginErrors.clear();
            qIXPasswordRecoverErrors.clear();
            qIXPasswordRecoverMsg.clear();

            if(!qIXTextField.text.length || !qIXTextField.logic.veryfiEmail()) {
                qIXLoginErrors.addMessage(qIXLoginErrors.invalidEmail);
                return;
            }

            qIXButton1.enabled = false;
            ixloginscreen.recoverAccountPassword(qIXTextField.text);
        }
    }

    QIXLoginErrors {
        id: qIXLoginErrors
        anchors.bottom: qIXTextField.top
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    QIXPasswordRecoverErrors {
        id: qIXPasswordRecoverErrors
        anchors.bottom: qIXTextField.top
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    QIXPasswordRecoverMsg {
        id: qIXPasswordRecoverMsg
        anchors.bottom: qIXTextField.top
        anchors.bottomMargin: 20
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
