import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindow 1.0


Window {
    id: window
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
}
