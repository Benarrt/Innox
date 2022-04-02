import QtQuick 2.15

QIXTextListModel {
    id: control

    Component.onCompleted: {
        control.insert( QT_TR_NOOP("Magazyn"));
        control.insert( QT_TR_NOOP("Profil"));
    }
}
