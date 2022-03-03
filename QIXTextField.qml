import QtQuick 2.15
import QtQuick.Controls 2.15
import io.qt.examples.ixtextfield 1.0

QIXTextFieldBase {
    property var logic: ixTextField
    text: "QIXTextField"

    IXTextField {
        id: ixTextField
        component: parent
    }
}
