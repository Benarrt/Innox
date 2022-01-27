import QtQuick 2.15
import QtQuick.Controls 2.15

SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: 0
    clip: true

    QIXLoginPage {
    }

    QIXRegisterPage {
    }
}
