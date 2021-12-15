import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixpage 1.0

Page {

    property url currentPage

    onCurrentPageChanged: {
        ixpage.loadPage(currentPage);
    }

    IXPage {
        id: ixpage
    }
}
