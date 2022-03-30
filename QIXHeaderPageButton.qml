import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixheaderpagebuton 1.0

Item {
    id: control
    property var logic: iXHeaderPageButon
    property var text: "QIXHeaderPageButton"
    property var bridge:  parent.bridge
    property int itemId:  parent.itemId
    property bool current: false
    width: 100
    height: 70
    clip: true

    Component.onDestruction: {
        control.bridge.currentIndexChanged.disconnect(control.isCurrent);
    }

    onParentChanged: {
        if(!parent)
            return;

        control.bridge = parent.bridge;
        control.itemId = parent.itemId;
        control.bridge.currentIndexChanged.connect(control.isCurrent);
        isCurrent();
    }

    function isCurrent() {
        control.current = itemId === control.bridge.currentIndex;
    }

    onCurrentChanged: {
        if(current) {
            qIXButton.enabled = false;
            qIXButton.scale = 0.9;
            qIXButton.bgColor = IXStyleSheet.lightColor()
        } else {
            qIXButton.enabled = true;
            qIXButton.scale = 1;
            qIXButton.bgColor = IXStyleSheet.superLightColor();
        }
    }

    QIXButton {
        id: qIXButton
        anchors.fill: parent
        bgColor: IXStyleSheet.superLightColor()
        textColor: IXStyleSheet.mediumColor()
        text: bridge.pageName(itemId);

        onClicked: {
            opacity = 1;
            bridge.currentIndex = control.itemId;
        }
    }

    IXHeaderPageButon {
        id: iXHeaderPageButon
        component: control
    }
}


