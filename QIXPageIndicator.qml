import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixpageindicator 1.0
import io.qt.examples.ixstylesheet 1.0

PageIndicator {
    property var logic: ixPageIndicator
    id: pageIndicator
    spacing: 15
    delegate: Rectangle {
        implicitWidth: 15
        implicitHeight: 15

        radius: width / 2
        color: index === pageIndicator.currentIndex ? IXStyleSheet.mediumColor() : IXStyleSheet.darkColor()
        scale: index === pageIndicator.currentIndex ? 2 : 1
        border.width: 0

        Behavior on color {
            ColorAnimation {
                duration: 200
            }
        }

        Behavior on scale {
            PropertyAnimation {
                duration: 200
            }
        }
    }

    IXPageIndicator {
        id: ixPageIndicator
        component: parent
    }
}
