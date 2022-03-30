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

    Component.onCompleted: {
        listModel.clear();
        iXHeaderPageButtonBridge.feedPageNameListModel(pageNameListModel);
        var delegateCount = iXHeaderPageButtonBridge.delegatesCount();
        for(var i = 0; i < delegateCount; i++) {
            listModel.append({
                                 _url: iXHeaderPageButtonBridge.delegateUrl(),
                                 _itemId: i,
                             });
        }
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

            bridge: iXHeaderPageButtonBridge

            model: ListModel {
                id: listModel
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

    ListModel {
        id: pageNameListModel
        function pageName(index) {
            if(index < pageNameListModel.count) {
                return qsTr(pageNameListModel.get(index).name);

            }
            return qsTr("Nieznana");
        }

        ListElement {
            name: QT_TR_NOOP("Magazyn")
        }
        ListElement {
            name: QT_TR_NOOP("Profil")
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
        ListElement {
            name: "Zaslepka"
        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/
