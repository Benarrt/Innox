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
        iXHeaderPageButtonBridge.feedPageNameListModel(pageNameListModel);
        iXHeaderPageButtonBridge.feedModel(pageList.getListModel());
    }

    QIXDealerScreenHeaderPageList {
        id: pageList
        anchors.fill: parent
        bridge: iXHeaderPageButtonBridge
    }

    IXDealerScreenHeader {
        id: iXDealerScreenHeader
        component: parent
    }

    IXHeaderPageButtonBridge {
        id: iXHeaderPageButtonBridge
    }

    QIXDealerHeaderPageNameListModel {
        id: pageNameListModel
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/
