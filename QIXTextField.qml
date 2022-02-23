import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixtextfield 1.0
import io.qt.examples.ixstylesheet 1.0

TextField {
    text: "QIXTextField"
    horizontalAlignment: Text.AlignHCenter
    font: IXStyleSheet.fgFont()
    color: focus ? IXStyleSheet.fgColor() : IXStyleSheet.fg2Color()
    selectionColor: IXStyleSheet.fg3Color()

    background: Rectangle {
        color: IXStyleSheet.bgColor()
        border.color: IXStyleSheet.bg2Color()
        border.width: parent.focus ? 1 : 0
    }

    IXTextField {
        component: parent
    }
}
