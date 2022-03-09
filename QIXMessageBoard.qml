import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixmessageboard 1.0

Rectangle {
    id: rectangle
    color: IXStyleSheet.darkColor()
    border.width: 0
    radius: 5
    height: 0
    width: contentWidth
    visible: true
    clip: true
    opacity: 1

    property var logic: ixMessageBoard
    property color textColor: IXStyleSheet.redColor()
    property int fontSize: 16
    property int contentHeight: 40
    property int contentWidth: 650
    property int desiredHeight: 0

    property var messages: ListModel {
        ListElement {
            text: "QIXMessageBoardTEXT"
        }
    }

    onDesiredHeightChanged: {
        rectangle.height = rectangle.desiredHeight;
    }

    function addMessage(textId) {
        logic.addMessage(textId);
    }

    function addMessages(textIds) {
        logic.addMessages(textIds);
    }

    function clear() {
        logic.clear();
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

            function pushBack(textId) {
                append({_textId: textId});
            }

            ListElement {
                _color: "#63d01c"
                _text: "QIXMessageBoard"
                _textId: 0
                _fontSize: 20
            }
        }

        delegate: QIXLabel {

            function getText() {
                if(rectangle.messages.count > _textId)
                    return qsTr(rectangle.messages.get(_textId).text);

                return qsTr("Nieznana wiadomosc");
            }

            width: rectangle.contentWidth
            height: rectangle.contentHeight
            text: getText()
            color: rectangle.textColor
            font.pointSize: rectangle.fontSize
        }

    }

    IXMessageBoard {
        id: ixMessageBoard
        component: listView
    }
}
