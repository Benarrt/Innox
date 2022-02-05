import QtQuick 2.15
import io.qt.examples.ixwindow 1.0

IXWindow {
    component: parent
    onWidthChanged: {
        ixWindowScale.origin.x = width/2;
    }

    onHeightChanged:  {
        ixWindowScale.origin.y = height/2;
    }

    transform: Scale {
        id: ixWindowScale
        objectName: "ixWindowScale"
    }
}
