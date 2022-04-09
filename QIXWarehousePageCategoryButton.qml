import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixwarehousepagecategorybutton 1.0

Item {
    id: control
    property var logic: iXWarehousePageCategoryButton
    property var text: "QIXWarehousePageCategoryButton"
    property var bridge:  parent.bridge
    property int itemId:  parent.itemId
    width: 200
    height: 200
    clip: true

    Component.onDestruction: {
    }

    onParentChanged: {
        if(!parent)
            return;

        control.bridge = parent.bridge;
        control.itemId = parent.itemId;

        control.logic.setup();
    }

    QIXButton {
        id: qIXButton
        anchors.fill: parent
        bgColor: IXStyleSheet.lightColor()
        textColor: IXStyleSheet.darkColor()
        text: control.text;

        onClicked: {
            console.log("Category ", control.itemId);
        }
    }

    IXWarehousePageCategoryButton {
        id: iXWarehousePageCategoryButton
        component: control
    }
}


