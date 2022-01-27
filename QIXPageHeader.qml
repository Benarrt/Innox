import QtQuick 2.15
import io.qt.examples.ixpageheader 1.0


Item {

    property url contentUrl
    onContentUrlChanged: {
        ixpageHeader.loadPage(contentUrl);
    }

    IXPageHeader {
        id: ixpageHeader
    }
}
