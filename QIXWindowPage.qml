import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindowpage 1.0

Page {
    id: page
    property url contentUrl
    onContentUrlChanged: {
        ixwindowpage.url = contentUrl;
    }

    header: QIXWindowPageHeader {

    }

    footer: QIXWindowPageFooter {

    }

    IXWindowPage {
        //component: page
        anchors.fill: parent
        id: ixwindowpage
    }
}
