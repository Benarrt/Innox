import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixpasswordinput 1.0

QIXTextFieldBase {
    property var logic: ixPasswordInput
    text: "QIXPasswordInput"
    placeholderText: qsTr("haslo")
    echoMode: TextInput.Password

    IXPasswordInput {
        id: ixPasswordInput
        component: parent
    }
}
