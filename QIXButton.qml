import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixbutton 1.0
import io.qt.examples.ixstylesheet 1.0

Button {
    text: qsTr("QIXButton")
    font: IXStyleSheet.fgFont();
    display: AbstractButton.TextOnly
    scale: pressed ? 0.9 : 1
    opacity: 1

    onClicked: {
        opacity = 1
    }

    onHoveredChanged: {
        opacity = hovered ? 0.6 : 1
    }

    Behavior on scale {
        PropertyAnimation {
            duration: 100
        }
    }

    Behavior on opacity {
        PropertyAnimation {
            duration: 100
        }
    }

    contentItem: Text {
        text: parent.text
        font: parent.font
        color: IXStyleSheet.bgColor()
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        color: IXStyleSheet.fgColor()
        border.width: 0
    }

    IXButton {
        component: parent
    }
}
