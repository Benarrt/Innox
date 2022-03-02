import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixswipeview 1.0

SwipeView {
    id: swipeView
    property var logic: ixSwipeView
    IXSwipeView {
        id: ixSwipeView
        component: swipeView
    }

    Component.onDestruction: {
        console.log("SwipeView onDestroyed");
    }
}


