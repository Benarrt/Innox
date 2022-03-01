import QtQuick 2.15
import QtQuick.Controls 2.15

import io.qt.examples.ixstartupscreen 1.0

Item {
    property var logic: ixstartupscreen
    Component.onCompleted: {
        console.log("Component.onCompleted");
    }

    IXStartupScreen {
        component: parent
        id: ixstartupscreen
    }

    Component.onDestruction: {
        console.log("Destroyed");
    }
}
