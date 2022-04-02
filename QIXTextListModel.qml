import QtQuick 2.15

ListModel {
    id: control
    function text(index) {
        if(index < pageNameListModel.count) {
            return qsTr(control.get(index).text);

        }
        return qsTr("Nieznana");
    }

    function insert(_text) {
        control.append({text: _text});
    }
}
