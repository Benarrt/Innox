import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixswipeview 1.0

SwipeView {
    id: swipeView
    IXSwipeView {
        component: swipeView
    }

    Component.onDestruction: {
        console.log("SwipeView onDestroyed");
    }
}


