import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixpageindicator 1.0

PageIndicator {
    id: pageIndicator
    spacing: 15
    delegate: Rectangle {
        implicitWidth: 15
        implicitHeight: 15

        radius: width / 2
        color: index === pageIndicator.currentIndex ? "#FEFAD4" : "#8FB9A8"
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
        component: parent
    }
}
