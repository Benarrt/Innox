import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

QIXMessageBoard {

    property int registerInProgress: 0
    property int registerSuccess: 1
    color: IXStyleSheet.mediumColor()
    textColor: IXStyleSheet.superLightColor()

    messages: ListModel {
        ListElement {
            text: QT_TR_NOOP("Rejestracja w trakcie...")
        }

        ListElement {
            text: QT_TR_NOOP("Rejestracja zakonoczona, mozesz sie zalogowac")
        }
    }
}
