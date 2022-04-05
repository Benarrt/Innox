import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixgridview 1.0
import io.qt.examples.ixdynamicdelegate 1.0

Item {
    id: control
    width: 250
    height: 400
    property var logic: iXGridView
    property int itemW: 200
    property int itemH: 200
    property int itemSpacingW: 10
    property int itemSpacingH: 10
    property int maxColumns: 5
    property var bridge: control

    Component.onCompleted: {
        control.logic.setup();
    }

    property var model: ListModel {
        id: listModel
        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }

        ListElement {
            _url: "qrc:/QIXButton.qml"
            _itemId: 0
        }
    }

    GridView {
        id: gridView
        width: 250
        height: control.height
        flow: GridView.FlowLeftToRight
        flickableDirection: Flickable.VerticalFlick
        anchors.horizontalCenter: parent.horizontalCenter
        //contentHeight: height
        //contentWidth: width
        contentX: -control.itemSpacingW
        contentY: -control.itemSpacingH
        leftMargin: control.itemSpacingW
        topMargin: control.itemSpacingH
        layoutDirection: Qt.LeftToRight
        cellHeight: control.itemH + control.itemSpacingH
        cellWidth: control.itemW + control.itemSpacingW
        //boundsMovement: Flickable.StopAtBounds
        //boundsBehavior: Flickable.StopAtBounds
        clip: true

        delegate: Item {
            height: control.itemH
            width: control.itemW

            IXDynamicDelegate {
                id: iXDynamicDelegate
                width: parent.width
                height: parent.height
                bridge: control.bridge
                itemId: _itemId
            }

            Component.onCompleted: {
                iXDynamicDelegate.url = _url;
            }
        }

        model: control.model
    }

    IXGridView {
        id: iXGridView
        component: control
        gridView: gridView
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.75}
}
##^##*/
