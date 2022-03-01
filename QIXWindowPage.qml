import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindowpage 1.0

Page {
    property var logic: ixwindowpage
    id: page
    property url contentUrl

    background: Rectangle {
        color: "#00FFFFFF"
    }

    onContentUrlChanged: {
        ixwindowpage.url = contentUrl;
    }

    header: QIXWindowPageHeader {

    }

    footer: QIXWindowPageFooter {

    }

    IXWindowPage {
        component: page
        id: ixwindowpage
        anchors.fill: parent
    }
}
