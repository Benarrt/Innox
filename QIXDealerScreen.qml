import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixdealerscreen 1.0

Item {
    property var logic: ixDealerScreen
    anchors.fill: parent
    clip: true

    QIXSwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: 0

        QIXWarehousePage {
        }
    }

    IXDealerScreen {
        id: ixDealerScreen
        component: parent
    }
}
