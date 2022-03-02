import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

Item {
    width: 650
    height: 200
    clip: true

    property real desiredHeight: 200

    property bool tooShort: true
    property bool noUpper: true
    property bool noNumber: true
    property bool noSpecial: true
    property bool notEqual: true

    Component.onCompleted: {
        reset()
    }

    onDesiredHeightChanged: {
        height = desiredHeight
    }

    Behavior on height {
        PropertyAnimation {
            duration: 200
        }
    }

    function reset() {
        tooShort = false
        noUpper = false
        noNumber = false
        noSpecial = false
        notEqual = false
    }

    function showError(label) {
        label.visible = true
        label.height = 40
        desiredHeight += 40;
    }

    function hideError(label) {
        label.visible = false
        label.height = 0
        desiredHeight -= 40;
    }

    onTooShortChanged: {
        if(tooShort)
            showError(qIXLabel);
        else
            hideError(qIXLabel);
    }

    onNoUpperChanged: {
        if(noUpper)
            showError(qIXLabel1);
        else
            hideError(qIXLabel1);
    }

    onNoNumberChanged: {
        if(noNumber)
            showError(qIXLabel2);
        else
            hideError(qIXLabel2);
    }

    onNoSpecialChanged: {
        if(noSpecial)
            showError(qIXLabel3);
        else
            hideError(qIXLabel3);
    }

    onNotEqualChanged: {
        if(notEqual)
            showError(qIXLabel4);
        else
            hideError(qIXLabel4);
    }

    Rectangle {
        id: rectangle
        color: IXStyleSheet.darkColor()
        anchors.fill: parent
        border.width: 0
        radius: 5

        QIXLabel {
            id: qIXLabel
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            text: qsTr("Haslo musi miec conjamniej 8 znakow")
            color: "#c21313"

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

        }

        QIXLabel {
            id: qIXLabel1
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: qIXLabel.top
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            text: qsTr("Haslo musi miec conjamniej 1 duza litere")
            color: "#c21313"

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

        }

        QIXLabel {
            id: qIXLabel2
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: qIXLabel1.top
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            text: qsTr("Haslo musi miec conjamniej 1 cyfre")
            color: "#c21313"

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

        }

        QIXLabel {
            id: qIXLabel3
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: qIXLabel2.top
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            text: qsTr("Haslo musi miec conjamniej 1 znak specjalny")
            color: "#c21313"

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

        }

        QIXLabel {
            id: qIXLabel4
            height: 40
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: qIXLabel3.top
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            text: qsTr("Podane hasla musza byc identyczne")
            color: "#c21313"

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

        }
    }

}
