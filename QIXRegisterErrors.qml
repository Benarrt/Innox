import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

Item {
    width: 650
    height: 280
    clip: true

    property real desiredHeight: 280

    property bool tooShort: true
    property bool noUpper: true
    property bool noNumber: true
    property bool noSpecial: true
    property bool notEqual: true
    property bool invalidEmail: true
    property bool duplicatedEmail: true

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
        invalidEmail = false
        duplicatedEmail = false
    }

    function updateError(showNewError) {
        if(showNewError) {
            desiredHeight += 40;
        } else {
            desiredHeight -= 40;
        }
    }

    onTooShortChanged: {
        updateError(tooShort);
    }

    onNoUpperChanged: {
        updateError(noUpper);
    }

    onNoNumberChanged: {
        updateError(noNumber);
    }

    onNoSpecialChanged: {
        updateError(noSpecial);
    }

    onNotEqualChanged: {
        updateError(notEqual);
    }

    onInvalidEmailChanged: {
        updateError(invalidEmail);
    }

    onDuplicatedEmailChanged: {
        updateError(duplicatedEmail);
    }

    Rectangle {
        id: rectangle
        color: IXStyleSheet.darkColor()
        anchors.fill: parent
        border.width: 0
        radius: 5

        QIXLabel {
            id: qIXLabel
            height: tooShort ? 40 : 0
            opacity: tooShort ? 1 : 0
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

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }
        }

        QIXLabel {
            id: qIXLabel1
            height: noUpper ? 40 : 0
            opacity: noUpper ? 1 : 0
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

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }
        }

        QIXLabel {
            id: qIXLabel2
            height: noNumber ? 40 : 0
            opacity: noNumber ? 1 : 0
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

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }
        }

        QIXLabel {
            id: qIXLabel3
            height: noSpecial ? 40 : 0
            opacity: noSpecial ? 1 : 0
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

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }

        }

        QIXLabel {
            id: qIXLabel4
            height: notEqual ? 40 : 0
            opacity: notEqual ? 1 : 0
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

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }

        }

        QIXLabel {
            id: qIXLabel5
            height: invalidEmail ? 40 : 0
            opacity: invalidEmail ? 1 : 0
            color: "#c21313"
            text: qsTr("Podany email jest nieprawidlowy")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: qIXLabel4.top
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.rightMargin: 0

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }
        }

        QIXLabel {
            id: qIXLabel6
            height: duplicatedEmail ? 40 : 0
            opacity: duplicatedEmail ? 1 : 0
            color: "#c21313"
            text: qsTr("Istnieje juz konto z podanym adresem email")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: qIXLabel5.top
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.rightMargin: 0

            Behavior on height {
                PropertyAnimation {
                    duration: 200
                }
            }

            Behavior on opacity {
                PropertyAnimation {
                    duration: 200
                }
            }
        }
    }

}
