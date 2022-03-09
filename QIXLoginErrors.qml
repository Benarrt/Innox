import QtQuick 2.15

QIXMessageBoard {
    property int invalidEmail: 0
    property int invalidPassword: 1
    property int loginFailed: 2

    messages: ListModel {
        ListElement {
            text: QT_TR_NOOP("Podany email jest nieprawidlowy")
        }

        ListElement {
           text: QT_TR_NOOP("Haslo nie moze byc puste")
        }

        ListElement {
           text: QT_TR_NOOP("Logowanie nie powiodlo sie")
        }
    }
}
