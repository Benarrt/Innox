import QtQuick 2.15
import io.qt.examples.ixwindowpageheader 1.0

Item {
    property url contentUrl
    onContentUrlChanged: {
        ixWindowPageHeader.url = contentUrl;
    }

    IXWindowPageHeader {
        id: ixWindowPageHeader
    }
}
