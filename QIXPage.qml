import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixpage 1.0

Page {

    property url contentUrl
    onContentUrlChanged: {
        ixpage.load(contentUrl);
    }

    IXPage {
        id: ixpage
    }
}
