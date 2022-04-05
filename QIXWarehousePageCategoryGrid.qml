import QtQuick 2.15

QIXGridView {
    id: qIXGridView
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
