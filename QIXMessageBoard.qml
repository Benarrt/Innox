import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

Rectangle {
    id: rectangle
    color: IXStyleSheet.darkColor()
    border.width: 0
    radius: 5
    height: desiredHeight
    width: contentWidth
    visible: opacity > 0
    clip: true

    Component.onCompleted: {
        clear();
    }

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

    property color textColor: IXStyleSheet.redColor()
    property int fontSize: 16
    property int contentHeight: 40
    property int contentWidth: 650
    property int desiredHeight: 40

    function addText(textId, text) {
        listModel.append({
            _textId: textId,
            _text: text
        });
    }

    function removeText(textId) {
        for(var i = 0; i < listModel.count; i++) {
            if(listModel[i]._textId === textId) {
                listModel.remove(i);
                return;
            }
        }
    }

    function clear() {
        listModel.clear();
    }

    ListView {
        id: listView
        anchors.fill: parent
        snapMode: ListView.SnapToItem
        keyNavigationWraps: false
        interactive: false
        boundsMovement: Flickable.StopAtBounds
        boundsBehavior: Flickable.StopAtBounds
        contentWidth: rectangle.contentWidth
        contentHeight: rectangle.contentHeight

        model: ListModel {
            id: listModel

            ListElement {
                _color: "#63d01c"
                _text: "QIXMessageBoard"
                _textId: 0
                _fontSize: 20
            }

            onCountChanged: {
                if(count === 0) {
                    rectangle.opacity = 0
                } else if(count === 1) {
                    rectangle.opacity = 1
                }

                rectangle.desiredHeight = rectangle.contentHeight * listModel.count;            }
        }

        delegate: QIXLabel {
            width: rectangle.contentWidth
            height: rectangle.contentHeight
            text: _text
            color: rectangle.textColor
            font.pointSize: rectangle.fontSize
            property int textId: _textId
        }

    }
}
