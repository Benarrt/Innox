import QtQuick 2.15
import io.qt.examples.ixwindowpagefooter 1.0

Item {
    property var logic: ixWindowPageFooter
    id: item1
    property url contentUrl
    onContentUrlChanged: {
        ixWindowPageFooter.url = contentUrl;
    }

    IXWindowPageFooter {
        component: item1
        id: ixWindowPageFooter
    }
}
