import QtQuick 2.15
import io.qt.examples.ixstylesheet 1.0

QIXMessageBoard {

    property int recoverSucces: 0
    color: IXStyleSheet.mediumColor()
    textColor: IXStyleSheet.lightColor()

    messages: ListModel {
        ListElement {
            text: QT_TR_NOOP("Nowe haslo zostalo wyslane na zarejestrowany email")
        }
    }
}
