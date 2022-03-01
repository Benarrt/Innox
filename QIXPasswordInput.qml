import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixpasswordinput 1.0
import io.qt.examples.ixstylesheet 1.0

TextField {
    property var logic: ixPasswordInput
    text: "QIXPasswordInput"
    horizontalAlignment: Text.AlignHCenter
    font: IXStyleSheet.defaultFont()
    color: focus ? IXStyleSheet.superLightColor() : IXStyleSheet.lightColor()
    selectionColor: IXStyleSheet.darkColor()
    selectedTextColor: IXStyleSheet.lightColor()
    maximumLength: 100
    placeholderText: qsTr("haslo")
    echoMode: TextInput.Password

    background: Rectangle {
        color: IXStyleSheet.mediumColor()
        border.color: IXStyleSheet.darkColor()
        border.width: parent.focus ? 1 : 0
        radius: 5
    }

    IXPasswordInput {
        id: ixPasswordInput
        component: parent
    }
}
