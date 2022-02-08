import QtQuick 2.15
import io.qt.examples.ixwindowpageheader 1.0

Item {
    id: item1
    property url contentUrl
    onContentUrlChanged: {
        ixWindowPageHeader.url = contentUrl;
    }

    IXWindowPageHeader {
        component: item1
        id: ixWindowPageHeader
    }
}
