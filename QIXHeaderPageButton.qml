import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixheaderpagebuton 1.0

Item {
    id: control
    property var logic: iXHeaderPageButon
    property var text: "QIXHeaderPageButton"
    property var bridge:  parent.bridge
    property bool current: false
    width: 100
    height: 70
    clip: true

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
        text: parent.text
        bgColor: IXStyleSheet.superLightColor()
        textColor: IXStyleSheet.mediumColor()

        onClicked: {
            opacity = 1;
            current = true;
            parent.bridge.testFunction();
        }
    }

    IXHeaderPageButon {
        id: iXHeaderPageButon
        component: control
    }
}


