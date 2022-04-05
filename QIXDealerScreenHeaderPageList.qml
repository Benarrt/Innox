import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

Rectangle {
    id: control
    color: IXStyleSheet.mediumColor()
    property var bridge

    function getListModel() {
        return listModel;
    }

    QIXListView {
        anchors.fill: parent
        itemSpacingW: 10
        itemSpacingH: 5
        itemW: 100
        itemH: 70
        id: qIXListView

        bridge: control.bridge

        model: listModel
    }

    ListModel {
        id: listModel
        function pushBack(id, url) {
            listModel.append({
                _url: url,
                _itemId: id
            });
        }
    }
}
