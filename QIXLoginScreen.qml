import QtQuick 2.15
import QtQuick.Controls 2.15

import io.qt.examples.ixloginscreen 1.0

Item {
    anchors.fill: parent
    clip: true

    function changeScreenTest() {
        console.log("changeScreenTest2");
        ixloginscreen.changeScreenTest();
    }

    QIXSwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: 0

        QIXLoginPage {
        }

        QIXRegisterPage {
        }
    }

    IXLoginScreen {
        id: ixloginscreen
        component: parent
    }
}


