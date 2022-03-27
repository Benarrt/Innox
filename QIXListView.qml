import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixlistview 1.0
import io.qt.examples.ixdynamicdelegate 1.0

Item {
    id: control
    width: 500
    height: 50
    property var logic: iXListView
    property int itemW: 90
    property int itemH: 40
    property int itemSpacingW: 10
    property int itemSpacingH: 10

    property var model: ListModel {
        id: listModel
        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
        }
    }

    Component.onCompleted: {
        control.logic.setup();
    }

    ListView {
        id: listView
        width: 500
        height: control.height
        contentY: -itemSpacingH
        contentX: -itemSpacingW
        orientation: ListView.Horizontal
        flickableDirection: Flickable.HorizontalFlick
        anchors.horizontalCenter: parent.horizontalCenter
        leftMargin: control.itemSpacingW
        topMargin: control.itemSpacingH
        layoutDirection: Qt.LeftToRight
        clip: true

        delegate: Item {
            width: control.itemW + control.itemSpacingW
            height: control.itemH + control.itemSpacingH

            Component.onCompleted: {
                iXDynamicDelegate.url = _url;
            }

            IXDynamicDelegate {
                id: iXDynamicDelegate
                width: control.itemW
                height: control.itemH
                bridge: _bridge()
            }
        }

        model: control.model
    }

    IXListView {
        id: iXListView
        component: control
        listView: listView
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.75}
}
##^##*/
