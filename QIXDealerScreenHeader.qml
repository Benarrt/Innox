import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixstylesheet 1.0
import io.qt.examples.ixdealerscreenheader 1.0
import io.qt.examples.ixheaderpagebuttonbridge 1.0

Item {
    id: control
    height: 80
    property var logic: iXDealerScreenHeader
    function currentPageChanged() {
        console.log("currentPageChanged");
    }

    Rectangle {
        id: rectangle
        color: IXStyleSheet.mediumColor()
        anchors.fill: parent

        QIXListView {
            anchors.fill: parent
            itemSpacingW: 10
            itemSpacingH: 5
            itemW: 100
            itemH: 70
            id: qIXListView

            model: ListModel {
                id: listModel
                ListElement {
                    _url: "qrc:/QIXHeaderPageButton.qml"
                    _bridge: function () {
                        return iXHeaderPageButtonBridge
                    }
                }
                ListElement {
                    _url: "qrc:/QIXHeaderPageButton.qml"
                    _bridge: function () {
                        return iXHeaderPageButtonBridge
                    }
                }
                ListElement {
                    _url: "qrc:/QIXHeaderPageButton.qml"
                    _bridge: function () {
                        return iXHeaderPageButtonBridge
                    }
                }
                ListElement {
                    _url: "qrc:/QIXHeaderPageButton.qml"
                    _bridge: function () {
                        return iXHeaderPageButtonBridge
                    }
                }
            }
        }
    }

    IXDealerScreenHeader {
        id: iXDealerScreenHeader
        component: parent
    }

    IXHeaderPageButtonBridge {
        id: iXHeaderPageButtonBridge
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
