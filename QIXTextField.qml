import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixtextfield 1.0

TextField {
    text: ixtextfield.text;
    selectByMouse: false
    IXTextField {
        id: ixtextfield
        property string text: ""
        Connections {
            function onSetData(data) {
                console.log("onSetData");
                console.log(data);
                ixtextfield.text = data;
            }
        }
    }
}
