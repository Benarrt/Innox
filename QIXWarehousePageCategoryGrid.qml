import QtQuick 2.15

QIXGridView {
    id: qIXGridView

    itemW: 200
    itemH: 200
    itemSpacingW: 10
    itemSpacingH: 10
    maxColumns: 5

    model: ListModel {
        id: listModel
        function pushBack(id, url) {
            listModel.append({
                _url: url,
                _itemId: id
            });
        }
    }
}
