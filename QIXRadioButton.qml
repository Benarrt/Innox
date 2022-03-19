import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixstylesheet 1.0

RadioButton {
    //property var logic: ixButton
    id: control
    text: qsTr("QIXButton")
    font: IXStyleSheet.defaultFont();
    display: AbstractButton.TextOnly
    hoverEnabled: true

    onHoveredChanged: {
        opacity = hovered ? 0.6 : 1
    }

    Behavior on opacity {
        PropertyAnimation {
            duration: 100
        }
    }

    contentItem: Text {
        text: parent.text
        font: parent.font
        color: control.checked ? IXStyleSheet.mediumColor() : IXStyleSheet.lightColor()
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        leftPadding: parent.indicator.width + parent.spacing
    }

    indicator: Rectangle {
        implicitWidth: 26
        implicitHeight: 26
        x: parent.leftPadding
        y: parent.height / 2 - height / 2
        radius: 13
        border.color: IXStyleSheet.mediumColor()
        border.width: 2;
        color: "#00ffffff"

        Rectangle {
            width: 14
            height: 14
            x: 6
            y: 6
            radius: 7
            color: IXStyleSheet.mediumColor()
            scale: control.checked ? 1 : 0

            Behavior on scale {
                PropertyAnimation {
                    duration: 100
                }
            }
        }
    }

    //IXButton {
       // id: ixButton
       // component: parent
    //}
}
