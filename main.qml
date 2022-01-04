import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindow 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")

    IXWindow {
        id: ixWindow

        QIXPage {
            id: qixpage
            currentPage: "qrc:/SwipePage1.qml"
            header: Label {
                text: qsTr("Main header")
                font.pixelSize: Qt.application.font.pixelSize * 2
                padding: 10
            }

            footer: Label {
                text: qsTr("Main Footer")
                font.pixelSize: Qt.application.font.pixelSize * 2
                padding: 10
            }
        }
    }

    MouseArea   {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton

        property bool editable: false

        onPressed: {
            console.log("Pressed");
            clearFoc
            focus = true;
            mouse.accepted = false;
        }
    }

    /*Rectangle {
        id: rectangle
        anchors.fill: parent;
        color: "#000000";
        border.color: "#eb1c1c"
        border.width: 20
        Component.onCompleted: {
            //ixWindow.setup(rectangle, 720, 1280)
        }

        IXWindow {
            id: ixWindow

            Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 0
                color: "#FFFFFF";
                width: 720
                height: 1280
            }
        }
    }*/

    /*footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }*/
}
