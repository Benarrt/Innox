import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixstylesheet 1.0

Label {
    width: 100
    height: 25
    font: IXStyleSheet.defaultFont()
    color: IXStyleSheet.lightColor()
    text: qsTr("QIXLabel")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
}

/*##^##
Designer {
    D{i:0;formeditorZoom:3}
}
##^##*/
