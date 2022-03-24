import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixdealerscreenheader 1.0
import QtQuick.Controls 2.15

Item {
    height: 80
    property var logic: iXDealerScreenHeader

    Row {
        id: row
        anchors.fill: parent
        padding: 0
        topPadding: 0
        spacing: 10

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }

        Rectangle {
            width: 80
            height: 80
            color: IXStyleSheet.darkColor()
        }
    }

    IXDealerScreenHeader {
        id: iXDealerScreenHeader
        component: parent
    }


}

/*Item {
    height: 80
    property var logic: iXDealerScreenHeader

    Rectangle {
        id: rectangle
        color: IXStyleSheet.mediumColor()
        anchors.fill: parent

        QIXButton {
            id: qIXButton
            x: 490
            y: 14
            width: 100
            height: 40
            text: "Wyloguj"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 50

            onClicked: {
                iXDealerScreenHeader.logOut();
            }
        }

        IXDealerScreenHeader {
            id: iXDealerScreenHeader
            component: parent
        }
    }
}*/



/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/
