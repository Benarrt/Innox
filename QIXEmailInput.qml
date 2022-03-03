import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixemailinput 1.0

QIXTextFieldBase {
    property var logic: ixEmailInput
    text: "QIXEmailInput"
    placeholderText: qsTr("email")

    IXEmailInput {
        id: ixEmailInput
        component: parent
    }
}
