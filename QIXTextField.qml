import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixtextfield 1.0

TextField {
    text: ""
    selectByMouse: false
    onCursorPositionChanged: {
        console.log("onCursorPositionChanged", cursorPosition);
        ixtextfield.cursorPositionChanged(cursorPosition);
    }

    Connections {
        target: ixtextfield
        function onTextUpdated(cursorPos, data) {
            text = data;
            cursorPosition = cursorPos;
        }
    }

    IXTextField {
        id: ixtextfield
    }
}
