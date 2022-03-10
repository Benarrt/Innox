import QtQuick 2.15

QIXMessageBoard {

    property int recoverFailed: 0

    messages: ListModel {
        ListElement {
            text: QT_TR_NOOP("Nie udalo sie odzyskac hasla")
        }
    }
}
