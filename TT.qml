import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3


Frame {
    Layout.fillWidth: true
    ListView {
        implicitWidth: 250
        implicitHeight: 300
        clip: true
        anchors.fill: parent

        model: myModel

        delegate: RowLayout {
            width: parent.width
            TextField{
            text : model.ID
            Layout.fillWidth: true
            }
            TextField {
                text: model.note
                Layout.fillWidth: true
            }
        }
    }
}
