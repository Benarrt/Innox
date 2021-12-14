import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindow 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")

    Rectangle {
        id: rectangle
        anchors.fill: parent;
        color: "#000000";
        border.color: "#eb1c1c"
        border.width: 20
        Component.onCompleted: {
            ixWindow.setup(rectangle, 720, 1280)
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
    }

    /*SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
        }

        Page2Form {
        }
    }

    footer: TabBar {
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
