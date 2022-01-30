import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixwindowpage 1.0

Page {

    property url contentUrl
    onContentUrlChanged: {
        ixwindowpage.load(contentUrl);
    }

    header: QIXWindowPageHeader {

    }

    IXWindowPage {
        id: ixwindowpage
    }
}