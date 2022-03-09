import QtQuick 2.15

QIXMessageBoard {

    property int tooShort: 0
    property int noUpper: 1
    property int noNumber: 2
    property int noSpecial: 3
    property int duplicatedEmail: 4
    property int invalidEmail: 5
    property int notEqualPws: 6
    property int unknownError: 7

    messages: ListModel {
        ListElement {
            text: QT_TR_NOOP("Haslo musi miec conjamniej 8 znakow")
        }

        ListElement {
            text: QT_TR_NOOP("Haslo musi miec conjamniej 1 duza litere")
        }

        ListElement {
            text: QT_TR_NOOP("Haslo musi miec conjamniej 1 cyfre")
        }

        ListElement {
            text: QT_TR_NOOP("Haslo musi miec conjamniej 1 znak specjalny")
        }

        ListElement {
            text: QT_TR_NOOP("Istnieje juz konto z podanym adresem email")
        }

        ListElement {
            text: QT_TR_NOOP("Podany email jest nieprawidlowy")
        }

        ListElement {
           text: QT_TR_NOOP("Podane hasla musza byc identyczne")
        }

        ListElement {
           text: QT_TR_NOOP("Wystapil nieznay blad")
        }
    }
}
