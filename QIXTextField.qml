import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixtextfield 1.0
import io.qt.examples.ixstylesheet 1.0

TextField {
    text: "QIXTextField"
    horizontalAlignment: Text.AlignHCenter
    font: IXStyleSheet.defaultFont()
    color: focus ? IXStyleSheet.superLightColor() : IXStyleSheet.lightColor()
    selectionColor: IXStyleSheet.darkColor()
    selectedTextColor: IXStyleSheet.lightColor()

    background: Rectangle {
        color: IXStyleSheet.mediumColor()
        border.color: IXStyleSheet.darkColor()
        border.width: parent.focus ? 1 : 0
        radius: 5
    }

    IXTextField {
        component: parent
    }
}
