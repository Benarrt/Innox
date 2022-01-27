import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindow 1.0


Window {
    id: window
    width: 720
    height: 1280
    visible: true
    title: qsTr("Tabs")

    IXWindow {
        id: ixWindow

        QIXPage {
            id: qixpage

            Component.onCompleted: {
                qixpage.contentUrl = "qrc:/QIXLoginScreen.qml"
            }
        }

        QIXHandleBackPopup {
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
