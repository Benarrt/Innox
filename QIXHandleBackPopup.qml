import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixhandlebackpopup 1.0

Item {
    id: item
    width: 350
    height: 150
    objectName: "handleBackPopup"
    visible: false
    Pane {
        id: pane
        height: 200
        anchors.fill: parent
        font.pointSize: 19

        Label {
            id: label
            text: qsTr("Quit INNOX app?")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        QIXButton {
            id: buttonYes
            width: 100
            height: 50
            text: qsTr("Yes")
            anchors.left: parent.left
            anchors.top: label.bottom
            anchors.topMargin: 50
            anchors.leftMargin: 50

            onClicked: {
                item.visible = false;
                ixHandleBackPopup.goBack();
            }
        }

        QIXButton {
            id: buttonNo
            x: 418
            width: 100
            height: 50
            text: qsTr("No")
            anchors.right: parent.right
            anchors.top: label.bottom
            anchors.topMargin: 50
            anchors.rightMargin: 50

            onClicked: {
                item.visible = false;
            }
        }
    }

    IXHandleBackPopup {
        id: ixHandleBackPopup;
    }
}
