import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixtextfield 1.0

TextField {
    text: ""
    selectByMouse: false

    Connections {
        target: ixtextfield
        function onTextUpdated(data) {
            text = data;
        }
    }

    IXTextField {
        id: ixtextfield
    }
}
