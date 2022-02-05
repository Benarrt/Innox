import QtQuick 2.15
import io.qt.examples.ixwindowpagefooter 1.0

Item {
    property url contentUrl
    onContentUrlChanged: {
        ixWindowPageFooter.url = contentUrl;
    }

    IXWindowPageFooter {
        component: parent
        id: ixWindowPageFooter
    }
}
